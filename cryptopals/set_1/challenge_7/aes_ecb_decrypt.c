#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

	int main() {
		const char aes_key[] = "YELLOW SUBMARINE";
		FILE * fp = fopen("C:\\Users\\Kellen\\Desktop\\aesencrypted.txt", "rb");
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


		int binsize = return_bin_size(filesize);
		char * aes_encrypted = base64_to_binary(b64text, binsize);
		printf("%d\n", binsize);
		AES_KEY AESkey;
		AES_set_decrypt_key(aes_key, 128, &AESkey);
		char * aes_decrypted = calloc(binsize + 1, sizeof(char));


		for (int i = 0; i < binsize; i += AES_BLOCK_SIZE) {
			AES_decrypt(aes_encrypted+i, aes_decrypted+i, &AESkey);
		}
		printf("%s\n", aes_decrypted);

		
		free(aes_encrypted);
		free(aes_decrypted);
		free(b64text);
		
		return 0;

	}