#include "b64.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
const char vals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char bin_val(char b64_c) {
	if (b64_c == '='){
		return 0;
	}
	for (int i = 0; i < 64; i++) {
		if (vals[i] == b64_c) {
			return i;
		}
	}
	return 0;
}

char * binary_to_base64(char * bin, int hex_len) {

	int remainder = (hex_len % 3);
	size_t size = ((hex_len * 2) + remainder) / 3;
	size += remainder;

	char * b64 = (char *)calloc(size + 1, sizeof(char));

	int i = 0;
	unsigned int j = 0;
	uint32_t bits = 0;
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

char * base64_to_binary(char * b64text) {
	/*
	size_t b64size = strlen(b64text);
	size_t binsize = ((b64size * 3) + (b64size % 4)) / 4;
	*/
	size_t b64size = strlen(b64text);
	size_t binsize = ((b64size * 3) + (b64size % 4)) / 4;
	char * bintext = calloc(binsize, sizeof(char));
	uint32_t bits = 0;
	int i = 0;
	for (int j = 0; j < binsize; j+=3) {
		bits = (bin_val(b64text[i]) << 18) | (bin_val(b64text[i + 1]) << 12) | (bin_val(b64text[i + 2]) << 6) | bin_val(b64text[i + 3]);
		bintext[j + 2] = bits & 0xff;
		bintext[j + 1] = (bits >> 8) & 0xff;
		bintext[j] = (bits >> 16) & 0xff;
		i += 4;
	}

	return bintext;
}
