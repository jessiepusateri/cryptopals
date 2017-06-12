#include "hex.h"
#include "ciph.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char input[] = { "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal" };
	char xor_key[] = {"ICE"};
	char * output = rolling_key_encryption(input, xor_key);
	printf("%s\n", output);

	
	
	return 0;
}