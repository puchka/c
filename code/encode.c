#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * src_file, * dst_file;
    unsigned char * a;
	src_file = fopen(argv[1], "rb");
    dst_file = fopen(argv[2], "wb");

    while(a=(unsigned char*)malloc(sizeof(char)),
            fread(a, sizeof(unsigned char), 1, src_file)
            ,!feof(src_file)){
        fprintf(dst_file,"%02x", *a);
        free(a);
        a++;
    }

    fclose (src_file);
    fclose (dst_file);
    
    return EXIT_SUCCESS;
}
