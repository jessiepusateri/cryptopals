size_t binsize = ((filesize * 3) + (filesize % 4)) / 4;

//Let KEYSIZE be the guessed length of the key; try values from 2 to(say) 40.
float min_edit_dist = MAX_INT;
int best_key_size = 0;

for (int key_size = 2; key_size <= 40; key_size++) {
	char * a = (char *)calloc(key_size + 1, sizeof(char));
	char * b = (char *)calloc(key_size + 1, sizeof(char));
	float curr_edit_distance = 0;

	for (int i = 0; (i + key_size) < (binsize / key_size); i += key_size) {
		memcpy(a, bin_val + (i * key_size), key_size);
		memcpy(b, bin_val + key_size + (i * key_size), key_size);
		float this_edit_dist = (edit_distance(a, b, key_size));// / key_size);
															   //this_edit_dist /= key_size;
		curr_edit_distance += this_edit_dist;

	}
	//curr_edit_distance /= (binsize / key_size);
	printf("%d : %.6f\n", key_size, curr_edit_distance / key_size);
}
/*
for (int key_size = 2; key_size <= 40; key_size++) {
char * a = (char *)calloc(key_size + 1, sizeof(char));
char * b = (char *)calloc(key_size + 1, sizeof(char));
//first two keys
memcpy(a, bin_val, key_size);
memcpy(b, bin_val + key_size, key_size);
float curr_edit_dist = edit_distance(a, b, key_size) / key_size;
//val1 = edit_distance(a, b);
//val1 /= key_size;
// second and third keys
memcpy(a, bin_val + (key_size * 2), key_size);
curr_edit_dist += edit_distance(a, b, key_size) / key_size;
//val2 = edit_distance(a, b);
//val2 /= key_size;
//third and fourth keys
memcpy(a, bin_val + (key_size * 3), key_size);
curr_edit_dist += edit_distance(a, b, key_size) / key_size;
//val3 = edit_distance(a, b);
//val3 /= key_size;
// averaging
curr_edit_dist /= 4;
//curr_edit_dist /= key_size;
//int curr_edit_dist = val1 + val2 + val3;
//curr_edit_dist /= 3;
printf("key = %d  edit dist = %.6f\n", key_size,curr_edit_dist);
//int curr_edit_dist = val1;
//if (curr_edit_dist < min_edit_dist) {
//	min_edit_dist = curr_edit_dist;
//	best_key_size = key_size;
//}
}*/

/*
size_t binsize = ((filesize * 3) + (filesize % 4)) / 4;
char * chunk = calloc(binsize / best_key_size, sizeof(char));
for (int j = 0; (j + best_key_size) <= binsize; j += best_key_size) {
memcpy(chunk, bin_val + j, best_key_size);
}
check_keys(chunk);
heap_sort_keys();
for (int i = 255; i > 240; i--) {
char * decoded = key_decrypt(chunk, keys[i].key_bits);
printf("%s\n", decoded);
}
//strlen is unreliable because of null characters

char * key = (char *)calloc(best_key_size + 1, sizeof(char));
size_t binsize = ((filesize * 3) + (filesize % 4)) / 4;
for (int i = 0; i <= best_key_size; i++) {

for (int j = i; (j + best_key_size) <= binsize; j += 14) {





}

}

*/