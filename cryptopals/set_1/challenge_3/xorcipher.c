#include "hex.h"
#include "ciph.h"
#include <stdio.h>
#include <stdint.h>


int main() {
	hex base = newhex("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
	check_keys(base->hex_to_binary(base));
	
	heap_sort_keys();
	char * decoded = key_decrypt(base->hex_to_binary(base), keys[0].key_bits);
	printf("The most likely key (in decimal) was: %d\n", keys[0].key_bits);
	printf("The output for this key is: %s\n", decoded); 


	return 0;
}