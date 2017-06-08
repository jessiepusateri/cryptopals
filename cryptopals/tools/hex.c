#include "hex.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//private
int binary_value(char h) {
	if (h >= '0' && h <= '9') return h - '0';
	if (h >= 'a' && h <= 'f') return h - 'a' + 0xa;
	else { return 0; }
}

int hex_value(char b) {
	if (b >= 0x0 && b <= 0x9) return b + '0';
	if (b >= 0xa && b <= 0xf) return b + 'a';
	else { return 0; }
}
//public
hex newhex(char * hex_string)
{
	if (strlen(hex_string) % 2 != 0) {
		printf("Bad length, expect errors.\n");
	}

	hex self = malloc(sizeof(struct hex_struct));

	self->hex_string = hex_string;
	self->length = &getlength;
	self->hex_to_binary = &htob;
	self->hex_xor = &xor;

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
