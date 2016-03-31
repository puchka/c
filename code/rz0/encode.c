#include <stdio.h>
/* [--] Include manquant. */
#include <string.h>

/* [!!] Utiliser unsigned char ; voir plus bas. */
void dec2bin(unsigned char dec, int *tab);
void bin2ch(int *bin, char *ch);
void strsplit(char *str, char *strs, int n, int m);
void bin2hex(char *ch, char *hex_str);

/* [--] Vaut mieux int main(void). */
int main()
{
        /*
         * [!!] Utiliser unsigned char pour un byte ; char c'est pour
         * des caractères uniquement, et peut être signed ou unsigned,
         * selon les implémentations. Avec char, problèmes de signes
         * et de conversion en tout genre => catastrophe.
         */
        unsigned char my_record;
        FILE *ptr_myfile;
        FILE *dest_file;
        int bin[8]={0};
        char ch[8];
        char hex_str[3];
        char src[25];
        char dst[25];
        printf("Nom du fichier source : ");
        /* [--] Pas de & devant src. */
        scanf("%s", &src);
        printf("Nom du fichier de destination : ");
        /* [--] Pas de & devant dst. */
        scanf("%s", &dst);
        ptr_myfile=fopen(src, "rb");
        dest_file = fopen(dst, "w");
        if (!ptr_myfile)
        {
                printf("Unable to open file!");
                return 1;
        }
        if (!dest_file)
        {
                printf("Unable to open destination file.\n");
                return 1;
        }
        int i=0;
        while (fread(&my_record,sizeof(char),1,ptr_myfile))
        {
                dec2bin(my_record, bin);
                bin2ch(bin, ch);
                bin2hex(ch, hex_str);
                fputs(hex_str, dest_file);
                i++;
                if (i%32==0) fputs("\n", dest_file);
        }
        fclose(ptr_myfile);
        fclose(dest_file);
        return 0;
}

/* [!!] Utiliser unsigned char ; pourquoi changer de type ? */
void  dec2bin(unsigned char dec, int tab[8])
{
    int i=7, b=0;
    /*
     * [!!] Il faut mettre les int restants à 0, sinon, au prochain
     * passage, il y a des restes indésirables...
     */
    memset(tab, 0, sizeof *tab * 8);
    while(dec>=1)
    {
        /* [--] La variable b sert un peu à rien... */
        b=dec%2;
        tab[i]=b;
        dec=dec/2;
        i--;
    }
}

void bin2ch(int *bin, char *ch)
{
        int i;
        for (i=0;i<8;i++)
        {
                if (bin[i]==1)
                {
                        ch[i]='1';
                }
                else
                {
                        ch[i]='0';
                }
        }
}

char ch2hex(char *ch)
{
        char hex;
        /*
         * [--] Indentation à revoir. Aussi, plus généralement, ne pas
         * mélanger pas de 4 et 8. D'autre part, énumérer toutes les
         * possibilités avec strcmp(), c'est pas top top...
         */
    if (!strcmp("0", ch))
        {
                hex = '0';
        }
        else if (!strcmp("00", ch))
        {
                hex = '0';
        }
        else if (!strcmp("000", ch))
        {
                hex = '0';
        }
        else if (!strcmp("0000", ch))
        {
        hex = '0';
        }
    else if (!strcmp("1", ch))
        {
                hex = '1';
        }
        else if (!strcmp("01", ch))
        {
                hex = '1';
        }
        else if (!strcmp("001", ch))
        {
                hex = '1';
        }
        else if (!strcmp("0001", ch))
        {
        hex = '1';
        }
    else if (!strcmp("10", ch))
        {
                hex = '2';
        }
        else if (!strcmp("010", ch))
        {
                hex = '2';
        }
        else if (!strcmp("0010", ch))
        {
        hex = '2';
        }
        else if (!strcmp("11", ch))
        {
                hex = '3';
        }
        else if (!strcmp("011", ch))
        {
                hex = '3';
        }
        else if (!strcmp("0011", ch))
        {
        hex = '3';
        }
        else if (!strcmp("100", ch))
        {
                hex = '4';
        }
        else if (!strcmp("0100", ch))
        {
        hex = '4';
        }
        else if (!strcmp("101", ch))
        {
                hex = '5';
        }
        else if (!strcmp("0101", ch))
        {
        hex = '5';
        }
    else if (!strcmp("110", ch))
        {
                hex = '6';
        }
        else if (!strcmp("0110", ch))
        {
        hex = '6';
        }
        else if (!strcmp("111", ch))
        {
                hex = '7';
        }
        else if (!strcmp("0111", ch))
        {
        hex = '7';
        }
    else if (!strcmp("1000", ch))
        {
        hex = '8';
        }
    else if (!strcmp("1001", ch))
        {
        hex = '9';
        }
    else if (!strcmp("1010", ch))
        {
        hex = 'A';
        }
    else if (!strcmp("1011", ch))
        {
        hex = 'B';
        }
    else if (!strcmp("1100", ch))
        {
        hex = 'C';
        }
    else if (!strcmp("1101", ch))
        {
        hex = 'D';
        }
    else if (!strcmp("1110", ch))
        {
        hex = 'E';
        }
    else if (!strcmp("1111", ch))
        {
        hex = 'F';
        }
        return hex;
}

void strsplit(char *str, char *strs, int n, int m)
{
        /*
         * [--] Utiliser l'arithmétique des pointeurs :
         *     strcpy(strs, str + n, m - n)
         * Ne pas nommer ses fonctions strxxx(), c'est réservé par
         * le langage.
         */
        int i;
        for (i=n;i<m;i++)
        {
                strs[i-n]=str[i];
        }
}

void bin2hex(char *ch, char *hex_str)
{
        char ch1[5];
        char ch2[5];
        strsplit(ch, ch1, 0 , 4);
        strsplit(ch, ch2, 4 , 8);
        ch1[4]='\0';
        ch2[4]='\0';
        hex_str[0] = ch2hex(ch1);
        hex_str[1] = ch2hex(ch2);
        hex_str[2] = '\0';
}
