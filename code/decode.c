#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * src_file, * dst_file;
    unsigned char * a;
    unsigned char * hex;
    src_file = fopen(argv[1], "rb");
    dst_file = fopen(argv[2], "wb");

	while(a=(char*)malloc(2),
        fread(a , sizeof(unsigned char), 2, src_file), !feof(src_file)){ 
        hex = (unsigned char*) malloc(2);
        sscanf(a, "%x", hex);
        fwrite(hex, sizeof(unsigned char), 1, dst_file);
        free(a);
    }

    fclose (src_file);
    fclose (dst_file);
    return EXIT_SUCCESS;
}
