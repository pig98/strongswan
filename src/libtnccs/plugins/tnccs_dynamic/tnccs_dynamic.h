/*
 * Copyright (C) 2011-2015 Andreas Steffen
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
 * @defgroup tnccs_dynamic_h tnccs_dynamic
 * @{ @ingroup tnccs_dynamic
 */

#ifndef TNCCS_DYNAMIC_H_
#define TNCCS_DYNAMIC_H_

#include <library.h>

#include <tnc/tnccs/tnccs.h>

/**
 * Create an instance of a dynamic TNC IF-TNCCS protocol handler.
 *
 * @param is_server		TRUE to act as TNC Server, FALSE for TNC Client
 * @param server_id		Server identity
 * @param peer_id		Client identity
 * @param server_ip		Server IP address
 * @param peer_ip		Client IP address
 * @param transport		Underlying IF-T transport protocol
 * @param cb			Callback function if TNC Server, NULL if TNC Client
 * @return				dynamic TNC IF-TNCCS protocol stack
 */
tnccs_t* tnccs_dynamic_create(bool is_server, identification_t *server_id,
							  identification_t *peer_id, host_t *server_ip,
							  host_t *peer_ip, tnc_ift_type_t transport,
							  tnccs_cb_t cb);

#endif /** TNCCS_DYNAMIC_H_ @}*/
