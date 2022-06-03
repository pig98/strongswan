/*
 * Copyright (C) 2010 Martin Willi
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
 * From McGrew & Viega
 * http://csrc.nist.gov/groups/ST/toolkit/BCM/documents/proposedmodes/gcm/gcm-revised-spec.pdf
 * Formatted to match our API which expects the first four bytes (salt) of the
 * IV as part of the key and writes/expects the ICV at the end of the cipher
 * text.
 * Since our implementations are currently limited to IV lengths of 12 (IV=8,
 * SALT=4 as per RFC 4106/5282) the test cases 5/6, 11/12 and 17/18 aren't
 * compatible.
 */
aead_test_vector_t aes_gcm1 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 16, .salt_size = 4,
	.len = 0, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "",
	.cipher	= "\x58\xe2\xfc\xce\xfa\x7e\x30\x61\x36\x7f\x1d\x57\xa4\xe7\x45\x5a",
};
aead_test_vector_t aes_gcm2 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 16, .salt_size = 4,
	.len = 16, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	.cipher	= "\x03\x88\xda\xce\x60\xb6\xa3\x92\xf3\x28\xc2\xb9\x71\xb2\xfe\x78"
			  "\xab\x6e\x47\xd4\x2c\xec\x13\xbd\xf5\x3a\x67\xb2\x12\x57\xbd\xdf",
};
aead_test_vector_t aes_gcm3_1 = {
	.alg = ENCR_AES_GCM_ICV8, .key_size = 16, .salt_size = 4,
	.len = 64, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39\x1a\xaf\xd2\x55",
	.cipher	= "\x42\x83\x1e\xc2\x21\x77\x74\x24\x4b\x72\x21\xb7\x84\xd0\xd4\x9c"
			  "\xe3\xaa\x21\x2f\x2c\x02\xa4\xe0\x35\xc1\x7e\x23\x29\xac\xa1\x2e"
			  "\x21\xd5\x14\xb2\x54\x66\x93\x1c\x7d\x8f\x6a\x5a\xac\x84\xaa\x05"
			  "\x1b\xa3\x0b\x39\x6a\x0a\xac\x97\x3d\x58\xe0\x91\x47\x3f\x59\x85"
			  "\x4d\x5c\x2a\xf3\x27\xcd\x64\xa6",
};
aead_test_vector_t aes_gcm3_2 = {
	.alg = ENCR_AES_GCM_ICV12, .key_size = 16, .salt_size = 4,
	.len = 64, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39\x1a\xaf\xd2\x55",
	.cipher	= "\x42\x83\x1e\xc2\x21\x77\x74\x24\x4b\x72\x21\xb7\x84\xd0\xd4\x9c"
			  "\xe3\xaa\x21\x2f\x2c\x02\xa4\xe0\x35\xc1\x7e\x23\x29\xac\xa1\x2e"
			  "\x21\xd5\x14\xb2\x54\x66\x93\x1c\x7d\x8f\x6a\x5a\xac\x84\xaa\x05"
			  "\x1b\xa3\x0b\x39\x6a\x0a\xac\x97\x3d\x58\xe0\x91\x47\x3f\x59\x85"
			  "\x4d\x5c\x2a\xf3\x27\xcd\x64\xa6\x2c\xf3\x5a\xbd",
};
aead_test_vector_t aes_gcm3_3 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 16, .salt_size = 4,
	.len = 64, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39\x1a\xaf\xd2\x55",
	.cipher	= "\x42\x83\x1e\xc2\x21\x77\x74\x24\x4b\x72\x21\xb7\x84\xd0\xd4\x9c"
			  "\xe3\xaa\x21\x2f\x2c\x02\xa4\xe0\x35\xc1\x7e\x23\x29\xac\xa1\x2e"
			  "\x21\xd5\x14\xb2\x54\x66\x93\x1c\x7d\x8f\x6a\x5a\xac\x84\xaa\x05"
			  "\x1b\xa3\x0b\x39\x6a\x0a\xac\x97\x3d\x58\xe0\x91\x47\x3f\x59\x85"
			  "\x4d\x5c\x2a\xf3\x27\xcd\x64\xa6\x2c\xf3\x5a\xbd\x2b\xa6\xfa\xb4",
};
aead_test_vector_t aes_gcm4 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 16, .salt_size = 4,
	.len = 60, .alen = 20,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2",
	.cipher = "\x42\x83\x1e\xc2\x21\x77\x74\x24\x4b\x72\x21\xb7\x84\xd0\xd4\x9c"
			  "\xe3\xaa\x21\x2f\x2c\x02\xa4\xe0\x35\xc1\x7e\x23\x29\xac\xa1\x2e"
			  "\x21\xd5\x14\xb2\x54\x66\x93\x1c\x7d\x8f\x6a\x5a\xac\x84\xaa\x05"
			  "\x1b\xa3\x0b\x39\x6a\x0a\xac\x97\x3d\x58\xe0\x91\x5b\xc9\x4f\xbc"
			  "\x32\x21\xa5\xdb\x94\xfa\xe9\x5a\xe7\x12\x1a\x47",
};
aead_test_vector_t aes_gcm7 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 24, .salt_size = 4,
	.len = 0, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "",
	.cipher	= "\xcd\x33\xb2\x8a\xc7\x73\xf7\x4b\xa0\x0e\xd1\xf3\x12\x57\x24\x35",
};
aead_test_vector_t aes_gcm8 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 24, .salt_size = 4,
	.len = 16, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	.cipher	= "\x98\xe7\x24\x7c\x07\xf0\xfe\x41\x1c\x26\x7e\x43\x84\xb0\xf6\x00"
			  "\x2f\xf5\x8d\x80\x03\x39\x27\xab\x8e\xf4\xd4\x58\x75\x14\xf0\xfb",
};
aead_test_vector_t aes_gcm9 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 24, .salt_size = 4,
	.len = 64, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39\x1a\xaf\xd2\x55",
	.cipher = "\x39\x80\xca\x0b\x3c\x00\xe8\x41\xeb\x06\xfa\xc4\x87\x2a\x27\x57"
			  "\x85\x9e\x1c\xea\xa6\xef\xd9\x84\x62\x85\x93\xb4\x0c\xa1\xe1\x9c"
			  "\x7d\x77\x3d\x00\xc1\x44\xc5\x25\xac\x61\x9d\x18\xc8\x4a\x3f\x47"
			  "\x18\xe2\x44\x8b\x2f\xe3\x24\xd9\xcc\xda\x27\x10\xac\xad\xe2\x56"
			  "\x99\x24\xa7\xc8\x58\x73\x36\xbf\xb1\x18\x02\x4d\xb8\x67\x4a\x14",
};
aead_test_vector_t aes_gcm10 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 24, .salt_size = 4,
	.len = 60, .alen = 20,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2",
	.cipher = "\x39\x80\xca\x0b\x3c\x00\xe8\x41\xeb\x06\xfa\xc4\x87\x2a\x27\x57"
			  "\x85\x9e\x1c\xea\xa6\xef\xd9\x84\x62\x85\x93\xb4\x0c\xa1\xe1\x9c"
			  "\x7d\x77\x3d\x00\xc1\x44\xc5\x25\xac\x61\x9d\x18\xc8\x4a\x3f\x47"
			  "\x18\xe2\x44\x8b\x2f\xe3\x24\xd9\xcc\xda\x27\x10\x25\x19\x49\x8e"
			  "\x80\xf1\x47\x8f\x37\xba\x55\xbd\x6d\x27\x61\x8c",
};
aead_test_vector_t aes_gcm13 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 32, .salt_size = 4,
	.len = 0, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "",
	.cipher	= "\x53\x0f\x8a\xfb\xc7\x45\x36\xb9\xa9\x63\xb4\xf1\xc4\xcb\x73\x8b",
};
aead_test_vector_t aes_gcm14 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 32, .salt_size = 4,
	.len = 16, .alen = 0,
	.key	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
			  "\x00\x00\x00\x00",
	.iv		= "\x00\x00\x00\x00\x00\x00\x00\x00",
	.plain	= "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	.cipher	= "\xce\xa7\x40\x3d\x4d\x60\x6b\x6e\x07\x4e\xc5\xd3\xba\xf3\x9d\x18"
			  "\xd0\xd1\xc8\xa7\x99\x99\x6b\xf0\x26\x5b\x98\xb5\xd4\x8a\xb9\x19",
};
aead_test_vector_t aes_gcm15 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 32, .salt_size = 4,
	.len = 64, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39\x1a\xaf\xd2\x55",
	.cipher	= "\x52\x2d\xc1\xf0\x99\x56\x7d\x07\xf4\x7f\x37\xa3\x2a\x84\x42\x7d"
			  "\x64\x3a\x8c\xdc\xbf\xe5\xc0\xc9\x75\x98\xa2\xbd\x25\x55\xd1\xaa"
			  "\x8c\xb0\x8e\x48\x59\x0d\xbb\x3d\xa7\xb0\x8b\x10\x56\x82\x88\x38"
			  "\xc5\xf6\x1e\x63\x93\xba\x7a\x0a\xbc\xc9\xf6\x62\x89\x80\x15\xad"
			  "\xb0\x94\xda\xc5\xd9\x34\x71\xbd\xec\x1a\x50\x22\x70\xe3\xcc\x6c",
};
aead_test_vector_t aes_gcm16 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 32, .salt_size = 4,
	.len = 60, .alen = 20,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d\xe6\x57\xba\x63\x7b\x39",
	.cipher	= "\x52\x2d\xc1\xf0\x99\x56\x7d\x07\xf4\x7f\x37\xa3\x2a\x84\x42\x7d"
			  "\x64\x3a\x8c\xdc\xbf\xe5\xc0\xc9\x75\x98\xa2\xbd\x25\x55\xd1\xaa"
			  "\x8c\xb0\x8e\x48\x59\x0d\xbb\x3d\xa7\xb0\x8b\x10\x56\x82\x88\x38"
			  "\xc5\xf6\x1e\x63\x93\xba\x7a\x0a\xbc\xc9\xf6\x62\x76\xfc\x6e\xce"
			  "\x0f\x4e\x17\x68\xcd\xdf\x88\x53\xbb\x2d\x55\x1b",
};

/**
 * Some self made vectors for AES-192/256 with ICV8/12
 */
aead_test_vector_t aes_gcm17 = {
	.alg = ENCR_AES_GCM_ICV8, .key_size = 24, .salt_size = 4,
	.len = 70, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x39\x80\xca\x0b\x3c\x00\xe8\x41\xeb\x06\xfa\xc4\x87\x2a\x27\x57"
			  "\x85\x9e\x1c\xea\xa6\xef\xd9\x84\x62\x85\x93\xb4\x0c\xa1\xe1\x9c"
			  "\x7d\x77\x3d\x00\xc1\x44\xc5\x25\xac\x61\x9d\x18\xc8\x4a\x3f\x47"
			  "\xb5\xb4\xa5\xeb\x10\x86\xcb\xdd\x59\x76\x52\x0d\xff\xa4\x85\x26"
			  "\x4b\x54\x22\xa0\xc6\x65\x4d\xa8\x46\x73\xec\xc0\x61\x68",
};
aead_test_vector_t aes_gcm18 = {
	.alg = ENCR_AES_GCM_ICV12, .key_size = 24, .salt_size = 4,
	.len = 70, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x39\x80\xca\x0b\x3c\x00\xe8\x41\xeb\x06\xfa\xc4\x87\x2a\x27\x57"
			  "\x85\x9e\x1c\xea\xa6\xef\xd9\x84\x62\x85\x93\xb4\x0c\xa1\xe1\x9c"
			  "\x7d\x77\x3d\x00\xc1\x44\xc5\x25\xac\x61\x9d\x18\xc8\x4a\x3f\x47"
			  "\xb5\xb4\xa5\xeb\x10\x86\xcb\xdd\x59\x76\x52\x0d\xff\xa4\x85\x26"
			  "\x4b\x54\x22\xa0\xc6\x65\x4d\xa8\x46\x73\xec\xc0\x61\x68\x0f\x00"
			  "\x0c\x32",
};
aead_test_vector_t aes_gcm19 = {
	.alg = ENCR_AES_GCM_ICV8, .key_size = 32, .salt_size = 4,
	.len = 70, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x52\x2d\xc1\xf0\x99\x56\x7d\x07\xf4\x7f\x37\xa3\x2a\x84\x42\x7d"
			  "\x64\x3a\x8c\xdc\xbf\xe5\xc0\xc9\x75\x98\xa2\xbd\x25\x55\xd1\xaa"
			  "\x8c\xb0\x8e\x48\x59\x0d\xbb\x3d\xa7\xb0\x8b\x10\x56\x82\x88\x38"
			  "\x68\xa0\xff\x03\xac\xdf\x95\x0e\x29\x65\x83\x7f\xda\x89\x72\xdd"
			  "\xd5\xc5\x96\xa3\x4a\xe0\xe6\x2f\x1e\xe2\x04\x80\xd7\xb7",
};
aead_test_vector_t aes_gcm20 = {
	.alg = ENCR_AES_GCM_ICV12, .key_size = 32, .salt_size = 4,
	.len = 70, .alen = 0,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x52\x2d\xc1\xf0\x99\x56\x7d\x07\xf4\x7f\x37\xa3\x2a\x84\x42\x7d"
			  "\x64\x3a\x8c\xdc\xbf\xe5\xc0\xc9\x75\x98\xa2\xbd\x25\x55\xd1\xaa"
			  "\x8c\xb0\x8e\x48\x59\x0d\xbb\x3d\xa7\xb0\x8b\x10\x56\x82\x88\x38"
			  "\x68\xa0\xff\x03\xac\xdf\x95\x0e\x29\x65\x83\x7f\xda\x89\x72\xdd"
			  "\xd5\xc5\x96\xa3\x4a\xe0\xe6\x2f\x1e\xe2\x04\x80\xd7\xb7\x5b\x65"
			  "\x9a\xad",
};

/**
 * Some self-made vectors using more associated data
 */
aead_test_vector_t aes_gcm21 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 16, .salt_size = 4,
	.len = 70, .alen = 69,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda"
			  "\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda\xd2\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xfe",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x42\x83\x1e\xc2\x21\x77\x74\x24\x4b\x72\x21\xb7\x84\xd0\xd4\x9c"
			  "\xe3\xaa\x21\x2f\x2c\x02\xa4\xe0\x35\xc1\x7e\x23\x29\xac\xa1\x2e"
			  "\x21\xd5\x14\xb2\x54\x66\x93\x1c\x7d\x8f\x6a\x5a\xac\x84\xaa\x05"
			  "\xb6\xf5\xea\x59\x55\x6f\x43\x93\xa8\xf4\x95\x8c\x14\x36\x3e\xf5"
			  "\x6c\xc2\x8a\x31\x64\xff\xe9\x24\x77\xc3\xaf\x6b\x64\xc7\x8b\xb9"
			  "\xec\xb9\x48\x84\xa2\xdb",
};
aead_test_vector_t aes_gcm22 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 24, .salt_size = 4,
	.len = 70, .alen = 69,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda"
			  "\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda\xd2\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xfe",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x39\x80\xca\x0b\x3c\x00\xe8\x41\xeb\x06\xfa\xc4\x87\x2a\x27\x57"
			  "\x85\x9e\x1c\xea\xa6\xef\xd9\x84\x62\x85\x93\xb4\x0c\xa1\xe1\x9c"
			  "\x7d\x77\x3d\x00\xc1\x44\xc5\x25\xac\x61\x9d\x18\xc8\x4a\x3f\x47"
			  "\xb5\xb4\xa5\xeb\x10\x86\xcb\xdd\x59\x76\x52\x0d\xff\xa4\x85\x26"
			  "\x4b\x54\x22\xa0\xc6\x65\x82\x33\xf3\x2d\x00\xe5\x03\x29\x8f\x7f"
			  "\x70\x74\xe6\xfe\x60\x75",
};
aead_test_vector_t aes_gcm23 = {
	.alg = ENCR_AES_GCM_ICV16, .key_size = 32, .salt_size = 4,
	.len = 70, .alen = 69,
	.key	= "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xfe\xff\xe9\x92\x86\x65\x73\x1c\x6d\x6a\x8f\x94\x67\x30\x83\x08"
			  "\xca\xfe\xba\xbe",
	.iv		= "\xfa\xce\xdb\xad\xde\xca\xf8\x88",
	.adata	= "\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce\xde\xad\xbe\xef"
			  "\xab\xad\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xda\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda"
			  "\xd2\xfe\xed\xfa\xce\xde\xad\xbe\xef\xfe\xda\xd2\xfe\xed\xfa\xce"
			  "\xde\xad\xbe\xef\xfe",
	.plain	= "\xd9\x31\x32\x25\xf8\x84\x06\xe5\xa5\x59\x09\xc5\xaf\xf5\x26\x9a"
			  "\x86\xa7\xa9\x53\x15\x34\xf7\xda\x2e\x4c\x30\x3d\x8a\x31\x8a\x72"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\x1c\x3c\x0c\x95\x95\x68\x09\x53\x2f\xcf\x0e\x24\x49\xa6\xb5\x25"
			  "\xb1\x6a\xed\xf5\xaa\x0d",
	.cipher	= "\x52\x2d\xc1\xf0\x99\x56\x7d\x07\xf4\x7f\x37\xa3\x2a\x84\x42\x7d"
			  "\x64\x3a\x8c\xdc\xbf\xe5\xc0\xc9\x75\x98\xa2\xbd\x25\x55\xd1\xaa"
			  "\x8c\xb0\x8e\x48\x59\x0d\xbb\x3d\xa7\xb0\x8b\x10\x56\x82\x88\x38"
			  "\x68\xa0\xff\x03\xac\xdf\x95\x0e\x29\x65\x83\x7f\xda\x89\x72\xdd"
			  "\xd5\xc5\x96\xa3\x4a\xe0\xa8\xb6\x0f\xfe\xd5\xe5\x33\xf4\x37\x74"
			  "\x83\x93\xf8\xaf\x80\x43",
};
