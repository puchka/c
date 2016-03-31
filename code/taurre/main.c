#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s input output\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *src = fopen(argv[1], "rb");
	FILE *dst = fopen(argv[2], "w");
	if (src == NULL || dst == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
	}

	int c;
	while ((c = getc(src)) != EOF) {
		fprintf(dst, "%02x", c);
	}

	fclose(src);
	fclose(dst);
	return EXIT_SUCCESS;
}
