#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *src_file = NULL, *dst_file = NULL;
    int nb_infos = 0, width, height, max;
    int i, j;
    unsigned char byte;
    char line[20], type[3];
    src_file = fopen("lena512.pgm", "r");
    if (src_file!=NULL){
        printf("Succes on opening src_file.\n");
        dst_file = fopen("lena512f.pgm", "w");
        if (src_file!=NULL){
            printf("Success on opening dst_file.\n");
            // Lecture des informations
            while (nb_infos<4)
            {
                fgets(line, 20, src_file);
                if (line[0]!='#')
                {
                    if (nb_infos==0)
                    {
                        strcpy(type, line);
                        type[2] = '\0';
                        nb_infos++;
                    }
                    else if (nb_infos==1)
                    {
                        sscanf(line, "%d %d", &width, &height);
                        nb_infos+=2;
                    }
                    else if (nb_infos==3)
                    {
                        sscanf(line, "%d", &max);
                        nb_infos++;
                    }
                }
            }
            printf("Type : %s\n", type);
            printf("Width : %d\n", width);
            printf("Height : %d\n", height);
            printf("Max : %d\n", max);
            unsigned char *buffer = (unsigned char *) malloc(width*height*sizeof(unsigned char));
            i = 0;
            do
            {
                byte = getc(src_file);
                buffer[i] = byte;
                i++;
            }
            while (byte!=EOF);
            // Ecrire les informations
            fprintf(dst_file, "%s\n", type);
            fprintf(dst_file, "%d %d\n", width, height);
            fprintf(dst_file, "%d\n", max);
            /*
            for (i=0;i<height;i++)
            {
                for (j=0;j<width;j++)
                {
                    printf("%c", buffer[height*i+j]);
                }
                printf("%c", '\n');
            }*/
            fclose(dst_file);
        } else{
            printf("Error on opening dst_file.\n");
        }
        fclose(src_file);
    } else{
        printf("Error on opening src_file.\n");
    }
    return EXIT_SUCCESS;
}
