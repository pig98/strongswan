/*
 * Copyright (C) 2012 Martin Willi
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
 * @defgroup lookip lookip
 * @ingroup cplugins
 *
 * @defgroup lookip_plugin lookip_plugin
 * @{ @ingroup lookip
 */

#ifndef LOOKIP_PLUGIN_H_
#define LOOKIP_PLUGIN_H_

#include <plugins/plugin.h>

typedef struct lookip_plugin_t lookip_plugin_t;

/**
 * Plugin providing fast connection lookup and notification for virtual IPs.
 */
struct lookip_plugin_t {

	/**
	 * Implements plugin interface.
	 */
	plugin_t plugin;
};

#endif /** LOOKIP_PLUGIN_H_ @}*/
