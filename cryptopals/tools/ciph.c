#include "ciph.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

key keys[256];

void clear_keys() {
	for (int i = 0; i < 256; i++) {
		keys[i].key_bits = 0;
		keys[i].key_val = 0;
	}
}

char * xor_mask(char * lhs, char * rhs, int hex_size) {

	size_t size = (hex_size / 2) + 1;
	char * xored = calloc(size, sizeof(char));
	//memset(xprted)

	for (int i = 0; i < size; i++) {
		xored[i] = ((char)* lhs) ^ ((char)* rhs);
		lhs++;
		rhs++;
	}

	return xored;
}

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
			keys[i].key_val += char_val((char) * (compare + j) ^ i);
			//keys[i].key_val += char_value((char) * (compare + j) ^ i);


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
			keys[largest] = temp_key;

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
/*
char * rolling_key_encryption(char * input, char * xor_key) {

	size_t size = strlen(input);
	char * a = input;

	char * hexed = (char *)calloc(2 * size + 1, sizeof(char));

	int key_length = strlen(xor_key);
	int key_loc = 0;

	for (int i = 0; i < 2 * size; i += 2) {
		char character = ((char)* a) ^ xor_key[key_loc];
		hexed[i] = hex_value(character >> 4);
		hexed[i + 1] = hex_value(character & 0x0f);
		a++;
		key_loc = (key_loc + 1) % key_length;
	}
	return hexed;
}
*/
char * rolling_key_encryption(char * input, char * xor_key, int binsize, int key_length) {

	char * a = input;
	char * result = (char *)calloc(binsize + 1, sizeof(char));
	int key_loc = 0;

	for (int i = 0; i < binsize; i++) {
		result[i] = ((char)* a) ^ xor_key[key_loc];
		a++;
		key_loc = (key_loc + 1) % key_length;
	}
	return result;
}

float hamming_dist(char left, char right) {
	float bits = 0;
	char val = left ^ right;
	while (val) {
		bits++;
		val &= val - 1; 
	}
	return bits;
}


float edit_distance(char * a, char * b, int key_size){
	/* in case of two different str len
	int max_len = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
	*/
	//size_t size = strlen(a) + 1;
	float diff_bits = 0;
	for (int i = 0; i < key_size; i++) {
		diff_bits += hamming_dist(a[i], b[i]);

	}
	return diff_bits;
}

int get_key_size(char * bin_val, int binsize) {
	//size_t binsize = ((filesize * 3) + (filesize % 4)) / 4;

	float best_key_score = 9999;
	int best_key = 0;
	for (int key_size = 2; key_size < 41; key_size++) {
		float curr_edit_distance = 0;
		char * a = (char *)calloc(key_size + 1, sizeof(char));
		char * b = (char *)calloc(key_size + 1, sizeof(char));
		float num_chunks = 0;
		for (int i = 0; (i + key_size) < binsize; i += key_size) {
			//printf("%d          %d\n", (i * key_size), binsize);
			memcpy(a, bin_val + i, key_size);
			memcpy(b, bin_val + i + key_size, key_size);
			float this_edit_dist = (edit_distance(a, b, key_size) / (float)key_size);
			//this_edit_dist /= key_size;
			curr_edit_distance += this_edit_dist;
			num_chunks++;
		}
		curr_edit_distance /= num_chunks;
		if (curr_edit_distance < best_key_score) {
			best_key = key_size;
			best_key_score = curr_edit_distance;
		}
	}
	return best_key;
}


char * get_key(char * bin_val, int key_size, int binsize) {
	char * key_chars = (char *)calloc(key_size + 1, sizeof(char));
	char * chunks = (char *)calloc((binsize/key_size) + 1, sizeof(char));

	int j = 0;
	for (j; j < key_size; j++) {
		for (int i = 0; (i * key_size) + j <= binsize; i++) {
			memcpy(chunks + i, bin_val + (key_size * i) + j /* + j */, sizeof(char));
		}
		check_keys(chunks);
		heap_sort_keys();
		key_chars[j] = keys[255].key_bits;
		clear_keys();
	}

	return key_chars;
}