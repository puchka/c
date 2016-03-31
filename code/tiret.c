#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * src_file, * dst_file;
    char a;
    src_file = fopen(argv[1], "r");
    dst_file = fopen(argv[2], "w");

	while(a=fgetc(src_file), !feof(src_file)){
        if (a!='­')
            fputc(a, dst_file);
    }

    fclose (src_file);
    fclose (dst_file);
    return EXIT_SUCCESS;
}
