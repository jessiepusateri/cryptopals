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

void heapify(int n, int i) {
	int looper = 1;
	while (looper) {
		looper = 0;
		int largest = i; 
		int l = 2 * i + 1;  
		int r = 2 * i + 2;  

		if (l < n && keys[l].key_val > keys[largest].key_val)
			largest = l;

		if (r < n && keys[r].key_val > keys[largest].key_val)
			largest = r;

		if (largest != i)
		{
			key temp_key = keys[i];
			keys[i] = keys[largest];
			keys[largest] = keys[i];

			looper = 1;
		}
	}
}

//note: this isn't necessary, it would be easier to just save the location max value, however, I was messing
//around with sorting algos

void heap_sort_keys()
{
	int array_size = 256;

	for (int i = array_size / 2 - 1; i >= 0; i--)
		heapify(array_size, i);


	for (int i = array_size - 1; i >= 0; i--)
	{

		key temp_key = keys[0];
		keys[0] = keys[i];
		keys[i] = temp_key;

		heapify(i, 0);
	}
}

