/*
 * Copyright (C) 2013 Andreas Steffen
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
 * @defgroup tnc_ifmap2_soap_msg tnc_ifmap2_soap_msg
 * @{ @ingroup tnc_ifmap2 
 */

#ifndef TNC_IFMAP2_SOAP_MSG_H_
#define TNC_IFMAP2_SOAP_MSG_H_

#include <library.h>
#include <tls_socket.h>

#include <libxml/parser.h>

typedef struct tnc_ifmap2_soap_msg_t tnc_ifmap2_soap_msg_t;

/**
 * Interface for sending and receiving SOAP-XML messages
 */
struct tnc_ifmap2_soap_msg_t {

	/**
	 * Post an IF-MAP request in a SOAP-XML message and return a result
	 *
	 * @param request_name	name of the IF-MAP request
	 * @param request		XML-encoded IF-MAP request
	 * @param result_name	name of the IF-MAP result
	 * @param result		XML-encoded IF-MAP result
	 */
	bool (*post)(tnc_ifmap2_soap_msg_t *this,
				 char *request_name, xmlNodePtr request,
				 char *result_name, xmlNodePtr* result);

	/**
	 * Destroy a tnc_ifmap2_soap_msg_t object.
	 */
	void (*destroy)(tnc_ifmap2_soap_msg_t *this);
};

/**
 * Create a tnc_ifmap2_soap_msg instance.
 *
 * @param tls	TLS socket protecting the SOAP message
 */
tnc_ifmap2_soap_msg_t *tnc_ifmap2_soap_msg_create(tls_socket_t *tls);

#endif /** TNC_IFMAP2_SOAP_MSG_H_ @}*/
