#pragma once
typedef struct key_struct {
	unsigned char key_bits;
	float key_val;
} key;

extern key keys[];

int get_char_value(unsigned char c);
char * key_decrypt(char * caesar, unsigned char keyval);
void check_keys(char * en_value);
void heap_sort_keys();
char * xor_mask(char * lhs, char * rhs, int hex_size);
char * rolling_key_encryption(char * input, char * xor_key, int binsize, int key_length);
	//int edit_distance(char * a, char * b);
int get_key_size(char * bin_val, int binsize);
char * get_key(char * bin_val, int key_size, int binsize);

//char table
float char_val(char c);

