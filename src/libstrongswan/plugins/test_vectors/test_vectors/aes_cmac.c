/*
 * Copyright (C) 2012 Tobias Brunner
 *
 * Copyright (C) secunet AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * RFC 4493 Example #1: AES-CMAC with 0-byte input
 */
prf_test_vector_t aes_cmac_p1 = {
	.alg = PRF_AES128_CMAC, .key_size = 16, .len = 0,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.seed	= "",
	.out	= "\xbb\x1d\x69\x29\xe9\x59\x37\x28\x7f\xa3\x7d\x12\x9b\x75\x67\x46"
};

/**
 * RFC 4493 Example #2: AES-CMAC with 16-byte input
 */
prf_test_vector_t aes_cmac_p2 = {
	.alg = PRF_AES128_CMAC, .key_size = 16, .len = 16,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.seed	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a",
	.out	= "\x07\x0a\x16\xb4\x6b\x4d\x41\x44\xf7\x9b\xdd\x9d\xd0\x4a\x28\x7c"
};

/**
 * RFC 4493 Example #3: AES-CMAC with 40-byte input
 */
prf_test_vector_t aes_cmac_p3 = {
	.alg = PRF_AES128_CMAC, .key_size = 16, .len = 40,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.seed	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
			  "\xae\x2d\x8a\x57\x1e\x03\xac\x9c\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
			  "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11",
	.out	= "\xdf\xa6\x67\x47\xde\x9a\xe6\x30\x30\xca\x32\x61\x14\x97\xc8\x27"
};

/**
 * RFC 4493 Example #4: AES-CMAC with 64-byte input
 */
prf_test_vector_t aes_cmac_p4 = {
	.alg = PRF_AES128_CMAC, .key_size = 16, .len = 64,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.seed	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
			  "\xae\x2d\x8a\x57\x1e\x03\xac\x9c\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
			  "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
			  "\xf6\x9f\x24\x45\xdf\x4f\x9b\x17\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
	.out	= "\x51\xf0\xbe\xbf\x7e\x3b\x9d\x92\xfc\x49\x74\x17\x79\x36\x3c\xfe"
};

/**
 * RFC 4615 Test Case #1: AES-CMAC with 20-byte input, 18-byte key
 */
prf_test_vector_t aes_cmac_p5 = {
	.alg = PRF_AES128_CMAC, .key_size = 18, .len = 20,
	.key	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f"
			  "\xed\xcb",
	.seed	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f"
			  "\x10\x11\x12\x13",
	.out	= "\x84\xa3\x48\xa4\xa4\x5d\x23\x5b\xab\xff\xfc\x0d\x2b\x4d\xa0\x9a"
};

/**
 * RFC 4615 Test Case #2: AES-CMAC with 20-byte input, 16-byte key
 */
prf_test_vector_t aes_cmac_p6 = {
	.alg = PRF_AES128_CMAC, .key_size = 16, .len = 20,
	.key	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f",
	.seed	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f"
			  "\x10\x11\x12\x13",
	.out	= "\x98\x0a\xe8\x7b\x5f\x4c\x9c\x52\x14\xf5\xb6\xa8\x45\x5e\x4c\x2d"
};

/**
 * RFC 4615 Test Case #3: AES-CMAC with 20-byte input, 10-byte key
 */
prf_test_vector_t aes_cmac_p7 = {
	.alg = PRF_AES128_CMAC, .key_size = 10, .len = 20,
	.key	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09",
	.seed	= "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f"
			  "\x10\x11\x12\x13",
	.out	= "\x29\x0d\x9e\x11\x2e\xdb\x09\xee\x14\x1f\xcf\x64\xc0\xb7\x2f\x3d"
};

/**
 * RFC 4494 Test Case #1: AES-CMAC-96 with 0-byte input
 */
signer_test_vector_t aes_cmac_s1 = {
	.alg = AUTH_AES_CMAC_96, .len = 0,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.data	= "",
	.mac	= "\xbb\x1d\x69\x29\xe9\x59\x37\x28\x7f\xa3\x7d\x12"
};


/**
 * RFC 4494 Test Case #2: AES-CMAC-96 with 16-byte input
 */
signer_test_vector_t aes_cmac_s2 = {
	.alg = AUTH_AES_CMAC_96, .len = 16,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.data	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a",
	.mac	= "\x07\x0a\x16\xb4\x6b\x4d\x41\x44\xf7\x9b\xdd\x9d"
};

/**
 * RFC 4494 Test Case #3: AES-CMAC-96 with 40-byte input
 */
signer_test_vector_t aes_cmac_s3 = {
	.alg = AUTH_AES_CMAC_96, .len = 40,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.data	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
			  "\xae\x2d\x8a\x57\x1e\x03\xac\x9c\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
			  "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11",
	.mac	= "\xdf\xa6\x67\x47\xde\x9a\xe6\x30\x30\xca\x32\x61"
};

/**
 * RFC 4494 Test Case #4: AES-CMAC-96 with 64-byte input
 */
signer_test_vector_t aes_cmac_s4 = {
	.alg = AUTH_AES_CMAC_96, .len = 64,
	.key	= "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
	.data	= "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
			  "\xae\x2d\x8a\x57\x1e\x03\xac\x9c\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
			  "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
			  "\xf6\x9f\x24\x45\xdf\x4f\x9b\x17\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
	.mac	= "\x51\xf0\xbe\xbf\x7e\x3b\x9d\x92\xfc\x49\x74\x17"
};
