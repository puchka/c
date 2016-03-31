#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100] = "122 221 234 134";
    int tab[4]={0};
    int i;
    char *str_nb;
    for (i=0;i<4;i++)
    {
        if (i==0)
            str_nb = strtok(text, " ");
        else
            str_nb = strtok(NULL, " ");
        tab[i] = strtol(str_nb, NULL, 10);
    }
    for (i=0;i<4;i++)
    {
        printf("%d\n", tab[i]);
    }
    return 0;
}
