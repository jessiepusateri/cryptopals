#include "hex.h"
#include <stdlib.h>
#include <string.h>


hex newhex(char * chars)
{
	hex self = (hex)malloc(sizeof(struct hex_struct));

	self->chars = chars;
	self->length = &getlength;

	return self;
}

int getlength(hex *self) {
	return strlen(((hex)self)->chars);
}
