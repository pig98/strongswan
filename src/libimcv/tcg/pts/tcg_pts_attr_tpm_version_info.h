/*
 * Copyright (C) 2011 Sansar Choinyambuu
 * Copyright (C) 2014 Andreas Steffen
 *
 * Copyright (C) secunet AG
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
 * @defgroup tcg_pts_attr_tpm_version_info tcg_pts_attr_tpm_version_info
 * @{ @ingroup tcg_attr
 */

#ifndef TCG_PTS_ATTR_TPM_VERSION_INFO_H_
#define TCG_PTS_ATTR_TPM_VERSION_INFO_H_

typedef struct tcg_pts_attr_tpm_version_info_t tcg_pts_attr_tpm_version_info_t;

#include "tcg/tcg_attr.h"
#include "pa_tnc/pa_tnc_attr.h"

/**
 * Class implementing the TCG PTS TPM Version Info Attribute
 *
 */
struct tcg_pts_attr_tpm_version_info_t {

	/**
	 * Public PA-TNC attribute interface
	 */
	pa_tnc_attr_t pa_tnc_attribute;

	/**
	 * Get TPM Version Info
	 *
	 * @return				TPM version info
	 */
	chunk_t (*get_tpm_version_info)(tcg_pts_attr_tpm_version_info_t *this);

	/**
	 * Set TPM Version Info
	 *
	 * @param tpm_version_info		TPM version info
	 */
	void (*set_tpm_version_info)(tcg_pts_attr_tpm_version_info_t *this,
				chunk_t tpm_version_info);
};

/**
 * Creates an tcg_pts_attr_tpm_version_info_t object
 *
 * @param tpm_version_info		TPM version info
 */
pa_tnc_attr_t* tcg_pts_attr_tpm_version_info_create(chunk_t tpm_version_info);

/**
 * Creates an tcg_pts_attr_tpm_version_info_t object from received data
 *
 * @param length			Total length of attribute value
 * @param value				Unparsed attribute value (might be a segment)
 */
pa_tnc_attr_t* tcg_pts_attr_tpm_version_info_create_from_data(size_t length,
															  chunk_t value);

#endif /** TCG_PTS_ATTR_TPM_VERSION_INFO_H_ @}*/
