#include <stdio.h>
#include <stdlib.h>

char *transcode(const char *src, int srcBase, char *dst, int dstBase);

int main(int argc, char **argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s input output\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE *src = fopen(argv[1], "r");
	FILE *dst = fopen(argv[2], "wb");
	if (src == NULL || dst == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
	}
	char hex[3], str_dec[4];
	int c;
	int dec;
	int i = 0;
	while ((c = getc(src)) != EOF) {
		hex[i%2] = c;
		if (i!=0 && i%2==0) {
			hex[2] = '\0';
			transcode(hex, 16, str_dec, 10);
			dec = strtol(str_dec, NULL, 10);
			fwrite(&dec, sizeof(char), 1, dst);
		}
		i++;
	}
	hex[2] = '\0';
	transcode(hex, 16, str_dec, 10);
	dec = strtol(str_dec, NULL, 10);
	fwrite(&dec, sizeof(char), 1, dst);
	fclose(src);
	fclose(dst);
	return EXIT_SUCCESS;
}

char *transcode(const char *src, int srcBase, char *dst, int dstBase) {
    long int val = strtol(src, NULL, srcBase);
    return itoa(val, dst, dstBase);
}
