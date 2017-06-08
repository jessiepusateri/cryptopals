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
