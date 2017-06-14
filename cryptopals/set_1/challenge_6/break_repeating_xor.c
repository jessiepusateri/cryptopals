#include "hex.h"
#include "b64.h"
#include "ciph.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE * fp = fopen("C:\\Users\\Kellen\\Desktop\\b64test.txt", "rb");
	if (fp == NULL)
	{
		perror("Error opening file");
		return(-1);
	}

	fseek(fp, 0L, SEEK_END);
	int filesize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char * b64text = calloc(filesize + 1, sizeof(char));
	char * b64pointer = b64text;
	while (1) {
		char ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		*b64pointer = ch;
		b64pointer++;
	}
	char * bin_val = base64_to_binary(b64text);
	int binsize = ((filesize * 3) + (filesize % 4)) / 4;

	int key_size = get_key_size(bin_val, binsize);
	char * xor_key = get_key(bin_val, key_size, binsize);

	char * result = rolling_key_encryption(bin_val, xor_key, binsize, key_size);
	printf("%s\n", result);


	free(bin_val);
	free(b64text);
	return 0;

}