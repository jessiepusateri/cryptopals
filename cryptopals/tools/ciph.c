#include "ciph.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


key keys[256];

char * key_decrypt(char * caesar, unsigned char keyval) {

	int size = strlen(caesar);
	char * key_xored = calloc(size + 1, sizeof(char));

	for (int i = 0; i < size; i++) {
		key_xored[i] = ((char)* caesar) ^ keyval;
		caesar++;
	}
	return key_xored;
}


int get_char_value(unsigned char xored_val) {
	//c11 standard doesnt support switch case ranges :(
	if (xored_val == ' ') {
		return 10;
	}
	else if (('a' <= xored_val) && (xored_val <= 'z')) {
		return 8;
	}
	else if ((('A' <= xored_val) && (xored_val <= 'Z')) || xored_val == '.' || xored_val == ',' || xored_val == 0x27) {
		return 3;
	}
	else if (xored_val == '\n' || xored_val == '\t') {
		return 2;
	}
	else if (('!' <= xored_val) && (xored_val <= '@')) {
		return 1;
	}
	else {
		return 0;
	}
}

void check_keys(char * en_value) {
	//strcpy(dest, src);
	int size = strlen(en_value);
	for (int i = 0x0; i <= 0xff; i += 0x1) {
		keys[i].key_bits = i;
		keys[i].key_val = 0;
		char * compare = calloc(size + 1, sizeof(char));
		memcpy(compare, en_value, size);

		for (int j = 0; j <= size; j++) {
			keys[i].key_val += get_char_value((char) * (compare + j) ^ i);

		}
	}

}

void sort_keys(){
	int change_occured = 1;
	while (change_occured) {
		change_occured = 0;
		for (int i = 0; i < 255; i++) {
			if (keys[i].key_val < keys[i + 1].key_val) {
				key temp = keys[i];
				keys[i] = keys[i + 1];
				keys[i + 1] = temp;
				change_occured = 1;
			}
		}
	}

}


/*
void check_keys(hex cipher) {
	const unsigned char initial_string = cipher->char

}
void sort_keys() {}

*/