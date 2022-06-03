/*
 * Copyright (C) 2015 Martin Willi
 *
 * Copyright (C) secunet AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version. See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * Test vectors from RFC6923/RFC7027
 */

dh_test_vector_t ecp224bp = {
	.group = ECP_224_BP, .priv_len = 28, .pub_len = 56, .shared_len = 28,
	.priv_a	= "\x7c\x4b\x7a\x2c\x8a\x4b\xad\x1f\xbb\x7d\x79\xcc\x09\x55\xdb\x7c"
			  "\x6a\x46\x60\xca\x64\xcc\x47\x78\x15\x9b\x49\x5e",
	.priv_b	= "\x63\x97\x6d\x4a\xae\x6c\xd0\xf6\xdd\x18\xde\xfe\xf5\x5d\x96\x56"
			  "\x9d\x05\x07\xc0\x3e\x74\xd6\x48\x6f\xfa\x28\xfb",
	.pub_a	= "\xb1\x04\xa6\x7a\x6f\x6e\x85\xe1\x4e\xc1\x82\x5e\x15\x39\xe8\xec"
			  "\xdb\xbf\x58\x49\x22\x36\x7d\xd8\x8c\x6b\xdc\xf2\x46\xd7\x82\xe7"
			  "\xfd\xb5\xf6\x0c\xd8\x40\x43\x01\xac\x59\x49\xc5\x8e\xdb\x26\xbc"
			  "\x68\xba\x07\x69\x5b\x75\x0a\x94",
	.pub_b	= "\x2a\x97\x08\x9a\x92\x96\x14\x7b\x71\xb2\x1a\x4b\x57\x4e\x12\x78"
			  "\x24\x5b\x53\x6f\x14\xd8\xc2\xb9\xd0\x7a\x87\x4e\x9b\x90\x0d\x7c"
			  "\x77\xa7\x09\xa7\x97\x27\x6b\x8c\xa1\xba\x61\xbb\x95\xb5\x46\xfc"
			  "\x29\xf8\x62\xe4\x4d\x59\xd2\x5b",
	.shared	= "\x31\x2d\xfd\x98\x78\x3f\x9f\xb7\x7b\x97\x04\x94\x5a\x73\xbe\xb6"
			  "\xdc\xcb\xe3\xb6\x5d\x0f\x96\x7d\xca\xb5\x74\xeb",
};

dh_test_vector_t ecp256bp = {
	.group = ECP_256_BP, .priv_len = 32, .pub_len = 64, .shared_len = 32,
	.priv_a	= "\x81\xdb\x1e\xe1\x00\x15\x0f\xf2\xea\x33\x8d\x70\x82\x71\xbe\x38"
			  "\x30\x0c\xb5\x42\x41\xd7\x99\x50\xf7\x7b\x06\x30\x39\x80\x4f\x1d",
	.priv_b	= "\x55\xe4\x0b\xc4\x1e\x37\xe3\xe2\xad\x25\xc3\xc6\x65\x45\x11\xff"
			  "\xa8\x47\x4a\x91\xa0\x03\x20\x87\x59\x38\x52\xd3\xe7\xd7\x6b\xd3",
	.pub_a	= "\x44\x10\x6e\x91\x3f\x92\xbc\x02\xa1\x70\x5d\x99\x53\xa8\x41\x4d"
			  "\xb9\x5e\x1a\xaa\x49\xe8\x1d\x9e\x85\xf9\x29\xa8\xe3\x10\x0b\xe5"
			  "\x8a\xb4\x84\x6f\x11\xca\xcc\xb7\x3c\xe4\x9c\xbd\xd1\x20\xf5\xa9"
			  "\x00\xa6\x9f\xd3\x2c\x27\x22\x23\xf7\x89\xef\x10\xeb\x08\x9b\xdc",
	.pub_b	= "\x8d\x2d\x68\x8c\x6c\xf9\x3e\x11\x60\xad\x04\xcc\x44\x29\x11\x7d"
			  "\xc2\xc4\x18\x25\xe1\xe9\xfc\xa0\xad\xdd\x34\xe6\xf1\xb3\x9f\x7b"
			  "\x99\x0c\x57\x52\x08\x12\xbe\x51\x26\x41\xe4\x70\x34\x83\x21\x06"
			  "\xbc\x7d\x3e\x8d\xd0\xe4\xc7\xf1\x13\x6d\x70\x06\x54\x7c\xec\x6a",
	.shared	= "\x89\xaf\xc3\x9d\x41\xd3\xb3\x27\x81\x4b\x80\x94\x0b\x04\x25\x90"
			  "\xf9\x65\x56\xec\x91\xe6\xae\x79\x39\xbc\xe3\x1f\x3a\x18\xbf\x2b",
};

dh_test_vector_t ecp384bp = {
	.group = ECP_384_BP, .priv_len = 48, .pub_len = 96, .shared_len = 48,
	.priv_a	= "\x1e\x20\xf5\xe0\x48\xa5\x88\x6f\x1f\x15\x7c\x74\xe9\x1b\xde\x2b"
			  "\x98\xc8\xb5\x2d\x58\xe5\x00\x3d\x57\x05\x3f\xc4\xb0\xbd\x65\xd6"
			  "\xf1\x5e\xb5\xd1\xee\x16\x10\xdf\x87\x07\x95\x14\x36\x27\xd0\x42",
	.priv_b	= "\x03\x26\x40\xbc\x60\x03\xc5\x92\x60\xf7\x25\x0c\x3d\xb5\x8c\xe6"
			  "\x47\xf9\x8e\x12\x60\xac\xce\x4a\xcd\xa3\xdd\x86\x9f\x74\xe0\x1f"
			  "\x8b\xa5\xe0\x32\x43\x09\xdb\x6a\x98\x31\x49\x7a\xba\xc9\x66\x70",
	.pub_a	= "\x68\xb6\x65\xdd\x91\xc1\x95\x80\x06\x50\xcd\xd3\x63\xc6\x25\xf4"
			  "\xe7\x42\xe8\x13\x46\x67\xb7\x67\xb1\xb4\x76\x79\x35\x88\xf8\x85"
			  "\xab\x69\x8c\x85\x2d\x4a\x6e\x77\xa2\x52\xd6\x38\x0f\xca\xf0\x68"
			  "\x55\xbc\x91\xa3\x9c\x9e\xc0\x1d\xee\x36\x01\x7b\x7d\x67\x3a\x93"
			  "\x12\x36\xd2\xf1\xf5\xc8\x39\x42\xd0\x49\xe3\xfa\x20\x60\x74\x93"
			  "\xe0\xd0\x38\xff\x2f\xd3\x0c\x2a\xb6\x7d\x15\xc8\x5f\x7f\xaa\x59",
	.pub_b	= "\x4d\x44\x32\x6f\x26\x9a\x59\x7a\x5b\x58\xbb\xa5\x65\xda\x55\x56"
			  "\xed\x7f\xd9\xa8\xa9\xeb\x76\xc2\x5f\x46\xdb\x69\xd1\x9d\xc8\xce"
			  "\x6a\xd1\x8e\x40\x4b\x15\x73\x8b\x20\x86\xdf\x37\xe7\x1d\x1e\xb4"
			  "\x62\xd6\x92\x13\x6d\xe5\x6c\xbe\x93\xbf\x5f\xa3\x18\x8e\xf5\x8b"
			  "\xc8\xa3\xa0\xec\x6c\x1e\x15\x1a\x21\x03\x8a\x42\xe9\x18\x53\x29"
			  "\xb5\xb2\x75\x90\x3d\x19\x2f\x8d\x4e\x1f\x32\xfe\x9c\xc7\x8c\x48",
	.shared	= "\x0b\xd9\xd3\xa7\xea\x0b\x3d\x51\x9d\x09\xd8\xe4\x8d\x07\x85\xfb"
			  "\x74\x4a\x6b\x35\x5e\x63\x04\xbc\x51\xc2\x29\xfb\xbc\xe2\x39\xbb"
			  "\xad\xf6\x40\x37\x15\xc3\x5d\x4f\xb2\xa5\x44\x4f\x57\x5d\x4f\x42",
};

dh_test_vector_t ecp512bp = {
	.group = ECP_512_BP, .priv_len = 64, .pub_len = 128, .shared_len = 64,
	.priv_a	= "\x16\x30\x2f\xf0\xdb\xbb\x5a\x8d\x73\x3d\xab\x71\x41\xc1\xb4\x5a"
			  "\xcb\xc8\x71\x59\x39\x67\x7f\x6a\x56\x85\x0a\x38\xbd\x87\xbd\x59"
			  "\xb0\x9e\x80\x27\x96\x09\xff\x33\x3e\xb9\xd4\xc0\x61\x23\x1f\xb2"
			  "\x6f\x92\xee\xb0\x49\x82\xa5\xf1\xd1\x76\x4c\xad\x57\x66\x54\x22",
	.priv_b	= "\x23\x0e\x18\xe1\xbc\xc8\x8a\x36\x2f\xa5\x4e\x4e\xa3\x90\x20\x09"
			  "\x29\x2f\x7f\x80\x33\x62\x4f\xd4\x71\xb5\xd8\xac\xe4\x9d\x12\xcf"
			  "\xab\xbc\x19\x96\x3d\xab\x8e\x2f\x1e\xba\x00\xbf\xfb\x29\xe4\xd7"
			  "\x2d\x13\xf2\x22\x45\x62\xf4\x05\xcb\x80\x50\x36\x66\xb2\x54\x29",
	.pub_a	= "\x0a\x42\x05\x17\xe4\x06\xaa\xc0\xac\xdc\xe9\x0f\xcd\x71\x48\x77"
			  "\x18\xd3\xb9\x53\xef\xd7\xfb\xec\x5f\x7f\x27\xe2\x8c\x61\x49\x99"
			  "\x93\x97\xe9\x1e\x02\x9e\x06\x45\x7d\xb2\xd3\xe6\x40\x66\x8b\x39"
			  "\x2c\x2a\x7e\x73\x7a\x7f\x0b\xf0\x44\x36\xd1\x16\x40\xfd\x09\xfd"
			  "\x72\xe6\x88\x2e\x8d\xb2\x8a\xad\x36\x23\x7c\xd2\x5d\x58\x0d\xb2"
			  "\x37\x83\x96\x1c\x8d\xc5\x2d\xfa\x2e\xc1\x38\xad\x47\x2a\x0f\xce"
			  "\xf3\x88\x7c\xf6\x2b\x62\x3b\x2a\x87\xde\x5c\x58\x83\x01\xea\x3e"
			  "\x5f\xc2\x69\xb3\x73\xb6\x07\x24\xf5\xe8\x2a\x6a\xd1\x47\xfd\xe7",
	.pub_b	= "\x9d\x45\xf6\x6d\xe5\xd6\x7e\x2e\x6d\xb6\xe9\x3a\x59\xce\x0b\xb4"
			  "\x81\x06\x09\x7f\xf7\x8a\x08\x1d\xe7\x81\xcd\xb3\x1f\xce\x8c\xcb"
			  "\xaa\xea\x8d\xd4\x32\x0c\x41\x19\xf1\xe9\xcd\x43\x7a\x2e\xab\x37"
			  "\x31\xfa\x96\x68\xab\x26\x8d\x87\x1d\xed\xa5\x5a\x54\x73\x19\x9f"
			  "\x2f\xdc\x31\x30\x95\xbc\xdd\x5f\xb3\xa9\x16\x36\xf0\x7a\x95\x9c"
			  "\x8e\x86\xb5\x63\x6a\x1e\x93\x0e\x83\x96\x04\x9c\xb4\x81\x96\x1d"
			  "\x36\x5c\xc1\x14\x53\xa0\x6c\x71\x98\x35\x47\x5b\x12\xcb\x52\xfc"
			  "\x3c\x38\x3b\xce\x35\xe2\x7e\xf1\x94\x51\x2b\x71\x87\x62\x85\xfa",
	.shared	= "\xa7\x92\x70\x98\x65\x5f\x1f\x99\x76\xfa\x50\xa9\xd5\x66\x86\x5d"
			  "\xc5\x30\x33\x18\x46\x38\x1c\x87\x25\x6b\xaf\x32\x26\x24\x4b\x76"
			  "\xd3\x64\x03\xc0\x24\xd7\xbb\xf0\xaa\x08\x03\xea\xff\x40\x5d\x3d"
			  "\x24\xf1\x1a\x9b\x5c\x0b\xef\x67\x9f\xe1\x45\x4b\x21\xc4\xcd\x1f",
};
