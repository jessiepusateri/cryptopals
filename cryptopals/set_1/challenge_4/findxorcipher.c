#include "hex.h"
#include "ciph.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


int main() {
	
	FILE * fp = fopen("C:\\Users\\Kellen\\Desktop\\encrypted.txt", "r");

	if (fp == NULL)
	{
		perror("Error opening file");
		return(-1);
	}
	
	char read_bytes[61];
	char max_bytes[61];
	//char * set_bytes = read_bytes;
//	hex max_hex;
	key max_key;
	max_key.key_bits = 0;
	max_key.key_val = 0;
	int character = 0;
	int i = 0;
	hex base;

	while ((character = fgetc(fp)) != EOF)
	{
		if (character == '\n') {
			read_bytes[i] = '\0';
			base = newhex(read_bytes);
			
			//checking
			check_keys(base->hex_to_binary(base));
			heap_sort_keys();
			if (keys[255].key_val > max_key.key_val) {
				max_key.key_bits = keys[255].key_bits;
				max_key.key_val = keys[255].key_val;
				strcpy(max_bytes, read_bytes);

			}
			//resetting array
			for (int i = 0; i < 256; i++) {
				keys[i].key_val = 0;
			}

			i = 0;
		
		
		
		} else {
			read_bytes[i] = (char)character;
			i++;
		}
	}
	
	//last line
	base = newhex(read_bytes);

	check_keys(base->hex_to_binary(base));
	heap_sort_keys();
	if (keys[255].key_val > max_key.key_val) {
		max_key = keys[255];
		strcpy(max_bytes, read_bytes);

	}
	
	hex max_hex = newhex(max_bytes);
	char * output = key_decrypt(max_hex->hex_to_binary(max_hex), max_key.key_bits);
	printf("The output for this key is: %s\n", output);


	return 0;
}