#include "cryptolib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char vals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int binval(char h) {
	if (h >= '0' && h <= '9') return h - '0';
	if (h >= 'a' && h <= 'f') return h - 'a' + 0xa;
	else { return 0; }
}


uint8_t * hextobin(uint8_t * hex) {
	size_t size = (strlen(hex) / 2) + 1;
	uint8_t * bin = (uint8_t *)calloc(size + 1, sizeof(uint8_t));

	int i = 0;
	while (i < size) {
		bin[i] = binval(*hex) << 4;
		hex += 1;
		bin[i] |= binval(*hex);

		hex++;
		i++;
	}
	return bin;
}


uint8_t * htob64(uint8_t * hex) {
	
	if (strlen(hex) % 2 != 0) { 
		printf("Bad length.\n");
		return '\0';
	}
	
	int remainder = (strlen(hex) % 3);
	size_t size = ((strlen(hex) * 2) + remainder) / 3;
	size += remainder;

	uint8_t * b64 = (uint8_t *)calloc(size+1, sizeof(uint8_t));
	uint8_t * bin = hextobin(hex);

	int i = 0; 
	int j = 0;
	uint32_t bits;
	for (j = 0; j < size-4; j += 4) {
		bits = (bin[i] << 16) | (bin[i + 1] << 8) | bin[i + 2];
	
		b64[j + 3] = vals[bits & 0x3f];
		b64[j + 2] = vals[(bits >> 6) & 0x3f];
		b64[j + 1] = vals[(bits >> 12) & 0x3f];
		b64[j] = vals[(bits >> 18) & 0x3f];
		i += 3;
	}

	bits = (bin[i] << 16) | (bin[i + 1] << 8) | bin[i + 2];
	b64[j + 1] = vals[(bits >> 12) & 0x3f];
	b64[j] = vals[(bits >> 18) & 0x3f];

	switch (remainder) {
	case 2: {
		b64[j + 3] = b64[j + 2] = '=';
		break; }
	case 1: {
		b64[j + 3] = '=';
		b64[j + 2] = vals[(bits >> 6) & 0x3f];
		break; }
	case 0: {
		b64[j + 3] = vals[bits & 0x3f];
		b64[j + 2] = vals[(bits >> 6) & 0x3f];
		break; }
	}

	return b64;
}