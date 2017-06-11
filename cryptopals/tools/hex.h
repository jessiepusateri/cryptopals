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
	hex(*hex_xor)(hex, hex);
	void(*new_string)(hex, char*);
	char *(*key_decrypt)(hex, unsigned char);

};


//function primitives
hex newhex(char * hex_string);
int getlength(hex self);
char * htob(hex self);
hex xor(hex self, hex rhs);
void new_s(hex self, char * hex_string);


