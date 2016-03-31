#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *carte_file = NULL;
    carte_file = fopen("carte.txt", "r");
    int i;
    char ch[20];
    if (carte_file!=NULL)
    {
        while (fgets(ch, 20, carte_file))
        {
            for (i=0;i<29;i++)
                if (ch[i]=='#')
                    ch[i]=254;
                else if (ch[i]=='.')
                    ch[i]=' ';
            printf("%s", ch);
        }
        printf("%c", '\n');
        fclose(carte_file);
    }
    else
    {
        printf("Error on reading carte.txt\n");
    }
    return 0;
}
