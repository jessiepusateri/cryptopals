#include "b64.h"
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdint.h>
const char vals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char * binary_to_base64(char * bin, int hex_len) {

	int remainder = (hex_len % 3);
	size_t size = ((hex_len * 2) + remainder) / 3;
	size += remainder;

	char * b64 = (char *)calloc(size + 1, sizeof(char));

	int i = 0;
	unsigned int j = 0;
	uint32_t bits;
	//skip last loop
	for (j = 0; j < size - 4; j += 4) {
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
	free(bin);
	return b64;
}