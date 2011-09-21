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

/**
 * @defgroup tcg_pts_attr_dh_nonce_params_req tcg_pts_attr_dh_nonce_params_req
 * @{ @ingroup tcg_pts_attr_dh_nonce_params_req
 */

#ifndef TCG_PTS_ATTR_DH_NONCE_PARAMS_REQ_H_
#define TCG_PTS_ATTR_DH_NONCE_PARAMS_REQ_H_

typedef struct tcg_pts_attr_dh_nonce_params_req_t tcg_pts_attr_dh_nonce_params_req_t;
typedef enum pts_dh_group_t pts_dh_group_t;

#include "tcg_attr.h"
#include "pa_tnc/pa_tnc_attr.h"

/**
 * PTS Diffie Hellman Group Values
 */
enum pts_dh_group_t {
	/** IKE Group 2 */
	PTS_DH_GROUP_IKE2 =					 (1<<15),
	/** IKE Group 5 */
	PTS_DH_GROUP_IKE5 =					 (1<<14),
	/** IKE Group 14 */
	PTS_DH_GROUP_IKE14 =				 (1<<13),
	/** IKE Group 19, Elliptic curves using NIST 256 bit prime modules */
	PTS_DH_GROUP_IKE19 =				 (1<<12),
	/** IKE Group 20, Elliptic curves using NIST 384 bit prime modules */
	PTS_DH_GROUP_IKE20 =				 (1<<11),
};

/**
 * Class implementing the TCG PTS DH Nonce Parameters Request Attribute
 */
struct tcg_pts_attr_dh_nonce_params_req_t {

	/**
	 * Public PA-TNC attribute interface
	 */
	pa_tnc_attr_t pa_tnc_attribute;

	/**
	 * Get Minimum nonce length
	 *
	 * @return				Minimum acceptable length of nonce
	 */
	u_int8_t (*get_min_nonce_len)(tcg_pts_attr_dh_nonce_params_req_t *this);

	/**
	 * Get supported Diffie Hellman Groups
	 *
	 * @return				Supported Diffie Hellman Groups
	 */
	pts_dh_group_t (*get_dh_groups)(tcg_pts_attr_dh_nonce_params_req_t *this);
};

/**
 * Creates an tcg_pts_attr_dh_nonce_params_req_t object
 *
 * @param min_nonce_len				Minimum acceptable length of nonce
 * @param dh_groups					Initiator's supported DH groups
 */
pa_tnc_attr_t* tcg_pts_attr_dh_nonce_params_req_create(u_int8_t min_nonce_len,
												pts_dh_group_t dh_groups);

/**
 * Creates an tcg_pts_attr_dh_nonce_params_req_t object from received data
 *
 * @param value						unparsed attribute value
 */
pa_tnc_attr_t* tcg_pts_attr_dh_nonce_params_req_create_from_data(chunk_t value);

#endif /** TCG_PTS_ATTR_DH_NONCE_PARAMS_REQ_H_ @}*/
