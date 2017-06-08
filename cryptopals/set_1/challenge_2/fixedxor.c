#include "hex.h"

#include <stdio.h>

int main() {
	hex base = newhex("1c0111001f010100061a024b53535009181c");
	hex mask = newhex("686974207468652062756c6c277320657965");
	hex xor_hex = base->hex_xor(base, mask);
	printf("%s\n", xor_hex->hex_string);
	return 0;
}