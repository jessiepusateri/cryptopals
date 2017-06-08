//#include "cryptolib.h"
#include "hex.h"
#include "b64.h"
#include <stdio.h>
#include <stdint.h>

int main() {
	char * example = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	hex e = newhex(example);
	char * b64 = binary_to_base64(e->hex_to_binary(e), e->length(e));
	printf("%s\n", b64);
	return 0;
}