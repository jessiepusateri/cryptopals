#pragma once
#ifndef HEX_H
#define Hex_H
#endif
struct hex_struct;
typedef struct hex_struct* hex;

struct hex_struct {

	char * hex_string;
	int(*length)(hex);
	char *(*hex_to_binary)(hex);
};


//function primitives
hex newhex(char * hex_string);
int getlength(hex self);
char * htob(hex self);
