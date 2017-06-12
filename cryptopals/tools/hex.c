#include "hex.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//start of hex class


//private
int binary_value(char h) {
	if (h >= '0' && h <= '9') return h - '0';
	if (h >= 'a' && h <= 'f') return h - 'a' + 0xa;
	else { return 0; }
}

int hex_value(char b) {
	if (b >= 0x0 && b <= 0x9) { return b + '0'; }
	if (b >= 0xa && b <= 0xf) { return b + 'a' - 0xa; }
	else { return 0; }
}
//public
hex newhex(char * hex_string)
{
	int remainder = strlen(hex_string) % 2;
	if (remainder) {
		printf("Bytes not aligned, expect errors.\n");
	}

	hex self = malloc(sizeof(struct hex_struct));

	self->hex_string = hex_string;
	self->length = &getlength;
	self->hex_to_binary = &htob;
	self->hex_xor = &xor;
	self->new_string = &new_s;
	//self->key_decrypt = &key_xor;

	return self;
}

int getlength(hex self) {
	return strlen(self->hex_string);
}

char * htob(hex self) {
	size_t size = self->length(self);
	size = (size / 2) + 1;
	char * bin = calloc(size + 1, sizeof(char));
	unsigned int i = 0;
	//pointer here will be the issue if there is another error
	char * j = self->hex_string;

	while (i < size) {
		bin[i] = binary_value((char) *j) << 4;
		j += 1;
		bin[i] |= binary_value((char) *j);
		j++;
		i++;
	} 
	return bin;
}

void new_s(hex self, char * hex_string) {
	free(self->hex_string);
	self->hex_string = hex_string;
}

hex xor(hex self, hex rhs) {

	char * xored = calloc(self->length(self) + 1, sizeof(char));
	//memset(xprted)
	char * a = self->hex_string;
	char * b = rhs->hex_string;

	for (int i = 0; i < self->length(self); i++) {
		xored[i] = hex_value(binary_value((char)* a) ^ binary_value((char)* b));
		a++;
		b++;
	} 

	hex xor_hex = newhex(xored);
	return xor_hex;
}


//end of hex class

//outside of hex class

char * rolling_key_encryption(char * input, char * xor_key) {

	size_t size = strlen(input);
	char * a = input;

	char * hexed = (char *)calloc(2 * size + 1, sizeof(char));

	int key_length = strlen(xor_key);
	int key_loc = 0;

	for (int i = 0; i < 2 * size; i += 2) {
		char character = ((char)* a) ^ xor_key[key_loc];
		hexed[i] = hex_value(character >> 4);
		hexed[i + 1] = hex_value(character & 0x0f);
		a++;
		key_loc = (key_loc + 1) % key_length;
	}
	return hexed;
}

char * characters_to_hex(char * characters) {
	
	char * hexed = (char *)calloc(2 * strlen(characters) + 1, sizeof(char));
	int place = 0;
	
	for (int i = 0; i < 2 * strlen(characters); i+=2) {
		hexed[i] = hex_value(characters[place] >> 4);
		hexed[i+1] = hex_value(characters[place] & 0x0f);
		place++;
	} 
	return hexed;
}