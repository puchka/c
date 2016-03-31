#include <stdio.h>
#include <math.h>

void hex2ch(char hex, char *ch);
void hex2bin(char *hex, int *bin);

/* [--] C'est char *argv[], pas char argv[]. */
int main(int argc, char argv[])
{
        FILE *src_file;
        FILE *dst_file;
        char src[25];
        char dst[25];
        printf("Enter the name of source file : ");
        scanf("%s", src);
        printf("Enter the name of destination file : ");
        scanf("%s", dst);
        src_file = fopen(src, "r");
        dst_file = fopen(dst, "wb");
        if (!src_file)
        {
                printf("Unable to read source file!\n");
                return 1;
        }
        if (!dst_file)
        {
                printf("Unable to read destination file!\n");
                return 1;
        }
        char c;
        char hex[2];
        int bin[8];
        /*
         * [--] Utiliser unsigned char pour un byte ; voir l'autre
         * fichier source.
         */
        unsigned char dec = 0;
        int i = 0;
        while (1)
        {
                c = fgetc(src_file);
                if (c==EOF)
                {
                        /* [!!] Devenu inutile de par la correction plus bas. */
                        /*
                        hex2bin(hex, bin);
                        int j;
                        for (j=0;j<8;j++)
                        {
                                if (bin[j]==1)
                                        dec+=pow(2, 7-j);
                        }
                        fwrite(&dec, sizeof(char), 1, dst_file);
                         */
                        break;
                }
                if (c!='\n')
                {
                        hex[i%2]=c;
                        /*
                         * [!!] Il faut tester i % 2 == 1, et pas i %
                         * 2 == 0, parce que tu viens d'écrire dans
                         * hex à la ligne au-dessus, donc si tu testes
                         * == 0, tu auras le premier demi-octet du
                         * byte suivant... teste par toi-même.
                         */
                        if (i%2==1)
                        {
                                hex2bin(hex, bin);
                                int j;
                                for (j=0;j<8;j++)
                                {
                                        /*
                                         * [--] Ne pas utiliser pow()
                                         * pour des entiers. Les
                                         * puissances de 2 se font
                                         * avec l'opérateur <<.
                                         */
                                        if (bin[j]==1)
                                                dec+=pow(2, 7-j);
                                }
                                fwrite(&dec, sizeof(char), 1, dst_file);
                                /*
                                 * [--] Ce serait beaucoup plus clair
                                 * (= moins d'erreurs potentielles...)
                                 * d'initialiser avant la boucle
                                 * au-dessus...
                                 */
                                dec = 0;
                        }
                        i++;
                }
        }
        fclose(src_file);
        fclose(dst_file);
        return 0;
}

void hex2ch(char hex, char *ch)
{
        switch (hex)
        {
                case '0':
                        /* [--] Utiliser strcpy(). */
                        ch[0] = '0';
                        ch[1] = '0';
                        ch[2] = '0';
                        ch[3] = '0';
                        break;
                case '1':
                        ch[0] = '0';
                        ch[1] = '0';
                        ch[2] = '0';
                        ch[3] = '1';
                        break;
                case '2':
                        ch[0] = '0';
                        ch[1] = '0';
                        ch[2] = '1';
                        ch[3] = '0';
                        break;
                case '3':
                        ch[0] = '0';
                        ch[1] = '0';
                        ch[2] = '1';
                        ch[3] = '1';
                        break;
                case '4':
                        ch[0] = '0';
                        ch[1] = '1';
                        ch[2] = '0';
                        ch[3] = '0';
                        break;
                case '5':
                        ch[0] = '0';
                        ch[1] = '1';
                        ch[2] = '0';
                        ch[3] = '1';
                        break;
                case '6':
                        ch[0] = '0';
                        ch[1] = '1';
                        ch[2] = '1';
                        ch[3] = '0';
                        break;
                case '7':
                        ch[0] = '0';
                        ch[1] = '1';
                        ch[2] = '1';
                        ch[3] = '1';
                        break;
                case '8':
                        ch[0] = '1';
                        ch[1] = '0';
                        ch[2] = '0';
                        ch[3] = '0';
                        break;
                case '9':
                        ch[0] = '1';
                        ch[1] = '0';
                        ch[2] = '0';
                        ch[3] = '1';
                        break;
                case 'A':
                        ch[0] = '1';
                        ch[1] = '0';
                        ch[2] = '1';
                        ch[3] = '0';
                        break;
                case 'B':
                        ch[0] = '1';
                        ch[1] = '0';
                        ch[2] = '1';
                        ch[3] = '1';
                        break;
                case 'C':
                        ch[0] = '1';
                        ch[1] = '1';
                        ch[2] = '0';
                        ch[3] = '0';
                        break;
                case 'D':
                        ch[0] = '1';
                        ch[1] = '1';
                        ch[2] = '0';
                        ch[3] = '1';
                        break;
                case 'E':
                        ch[0] = '1';
                        ch[1] = '1';
                        ch[2] = '1';
                        ch[3] = '0';
                        break;
                default:
                        ch[0] = '1';
                        ch[1] = '1';
                        ch[2] = '1';
                        ch[3] = '1';
        }
        ch[4] = '\0';
}

void hex2bin(char *hex, int *bin)
{
        char ch[5];
        int i;
        for (i=0;i<8;i++)
        {
                if (i<4)
                {
                        /*
                         * [--] À factoriser hors de la boucle ; là on
                         * fais un hex2ch() quatre fois sur le même
                         * hex[0]...
                         */
                        hex2ch(hex[0], ch);
                        if (ch[i]=='1') bin[i] = 1;
                        else bin[i] = 0;
                }
                else
                {
                        hex2ch(hex[1], ch);
                        if (ch[i-4]=='1') bin[i] = 1;
                        else bin[i] = 0;
                }
        }
}
