#include "hex.h"
#include "ciph.h"
#include <stdio.h>

int main() {
	hex base = newhex("1c0111001f010100061a024b53535009181c");
	hex mask = newhex("686974207468652062756c6c277320657965");
	hex result = newhex
	                 (characters_to_hex   
	                    (xor_mask    
						        (base->hex_to_binary(base), mask->hex_to_binary(mask), base->length(base))));

	printf("%s\n", result->hex_string);
	return 0;
}