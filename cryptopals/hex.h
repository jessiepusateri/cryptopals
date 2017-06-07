#pragma once

typedef struct hex_struct* hex;

struct hex_struct {

	char *chars;
	int(*length)(hex*);
};

//typedef struct hex_struct* hex;

int getlength(hex *self);

hex newhex(char * chars);