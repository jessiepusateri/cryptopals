#pragma once
typedef struct key_struct {
	unsigned char key_bits;
	int key_val;
} key;

extern key keys[];

int get_char_value(unsigned char c);
char * key_decrypt(char * caesar, unsigned char keyval);
void check_keys(char * en_value);
void heap_sort_keys();

