/*
 * Copyright (C) 2011 Sansar Choinyambuu
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "tcg_pts_attr_dh_nonce_params_req.h"

#include <pa_tnc/pa_tnc_msg.h>
#include <bio/bio_writer.h>
#include <bio/bio_reader.h>
#include <debug.h>

typedef struct private_tcg_pts_attr_dh_nonce_params_req_t private_tcg_pts_attr_dh_nonce_params_req_t;

/**
 * PTS DH Nonce Parameters Request
 * see section 3.8.1 of PTS Protocol: Binding to TNC IF-M Specification
 *
 *					   1				   2				   3
 *   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |	Reserved  | Min. Nonce Len |		D-H Group Set			|
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  
 */

#define PTS_DH_NONCE_PARAMS_REQ_SIZE			4
#define PTS_DH_NONCE_PARAMS_REQ_RESERVED		0x00

/**
 * Private data of an tcg_pts_attr_dh_nonce_params_req_t object.
 */
struct private_tcg_pts_attr_dh_nonce_params_req_t {

	/**
	 * Public members of tcg_pts_attr_dh_nonce_params_req_t
	 */
	tcg_pts_attr_dh_nonce_params_req_t public;

	/**
	 * Attribute vendor ID
	 */
	pen_t vendor_id;

	/**
	 * Attribute type
	 */
	u_int32_t type;

	/**
	 * Attribute value
	 */
	chunk_t value;

	/**
	 * Noskip flag
	 */
	bool noskip_flag;
	
	/**
	 * Minimum acceptable length of nonce
	 */
	u_int8_t min_nonce_len;

	/**
	 * Diffie Hellman group set
	 */
	pts_dh_group_t dh_groups;

};

METHOD(pa_tnc_attr_t, get_vendor_id, pen_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->vendor_id;
}

METHOD(pa_tnc_attr_t, get_type, u_int32_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->type;
}

METHOD(pa_tnc_attr_t, get_value, chunk_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->value;
}

METHOD(pa_tnc_attr_t, get_noskip_flag, bool,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->noskip_flag;
}

METHOD(pa_tnc_attr_t, set_noskip_flag,void,
	private_tcg_pts_attr_dh_nonce_params_req_t *this, bool noskip)
{
	this->noskip_flag = noskip;
}

METHOD(pa_tnc_attr_t, build, void,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	bio_writer_t *writer;

	writer = bio_writer_create(PTS_DH_NONCE_PARAMS_REQ_SIZE);
	writer->write_uint8(writer, PTS_DH_NONCE_PARAMS_REQ_RESERVED);
	writer->write_uint8(writer, this->min_nonce_len);
	writer->write_uint8(writer, this->dh_groups);
	
	this->value = chunk_clone(writer->get_buf(writer));
	writer->destroy(writer);
}

METHOD(pa_tnc_attr_t, process, status_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this, u_int32_t *offset)
{
	bio_reader_t *reader;
	u_int8_t reserved;
	u_int16_t dh_groups;

	if (this->value.len < PTS_DH_NONCE_PARAMS_REQ_SIZE)
	{
		DBG1(DBG_TNC, "insufficient data for PTS DH Nonce Parameters Request");
		*offset = 0;
		return FAILED;
	}
	reader = bio_reader_create(this->value);
	reader->read_uint8(reader, &reserved);
	reader->read_uint8(reader, &this->min_nonce_len);
	reader->read_uint16(reader, &dh_groups);
	this->dh_groups = dh_groups;
	reader->destroy(reader);

	return SUCCESS;
}

METHOD(pa_tnc_attr_t, destroy, void,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	free(this->value.ptr);
	free(this);
}

METHOD(tcg_pts_attr_dh_nonce_params_req_t, get_min_nonce_len, u_int8_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->min_nonce_len;
}

METHOD(tcg_pts_attr_dh_nonce_params_req_t, get_dh_groups, pts_dh_group_t,
	private_tcg_pts_attr_dh_nonce_params_req_t *this)
{
	return this->dh_groups;
}

/**
 * Described in header.
 */
pa_tnc_attr_t *tcg_pts_attr_dh_nonce_params_req_create(u_int8_t min_nonce_len,
												pts_dh_group_t dh_groups)
{
	private_tcg_pts_attr_dh_nonce_params_req_t *this;

	INIT(this,
		.public = {
			.pa_tnc_attribute = {
				.get_vendor_id = _get_vendor_id,
				.get_type = _get_type,
				.get_value = _get_value,
				.get_noskip_flag = _get_noskip_flag,
				.set_noskip_flag = _set_noskip_flag,
				.build = _build,
				.process = _process,
				.destroy = _destroy,
			},
			.get_min_nonce_len = _get_min_nonce_len,
			.get_dh_groups = _get_dh_groups,
		},
		.vendor_id = PEN_TCG,
		.type = TCG_PTS_DH_NONCE_PARAMS_REQ,
		.min_nonce_len = min_nonce_len,
		.dh_groups = dh_groups,
	);

	return &this->public.pa_tnc_attribute;
}

/**
 * Described in header.
 */
pa_tnc_attr_t *tcg_pts_attr_dh_nonce_params_req_create_from_data(chunk_t value)
{
	private_tcg_pts_attr_dh_nonce_params_req_t *this;

	INIT(this,
		.public = {
			.pa_tnc_attribute = {
				.get_vendor_id = _get_vendor_id,
				.get_type = _get_type,
				.get_value = _get_value,
				.get_noskip_flag = _get_noskip_flag,
				.set_noskip_flag = _set_noskip_flag,
				.build = _build,
				.process = _process,
				.destroy = _destroy,
			},
			.get_min_nonce_len = _get_min_nonce_len,
			.get_dh_groups = _get_dh_groups,
		},
		.vendor_id = PEN_TCG,
		.type = TCG_PTS_DH_NONCE_PARAMS_REQ,
		.value = chunk_clone(value),
	);

	return &this->public.pa_tnc_attribute;
}
