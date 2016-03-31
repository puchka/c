#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

char lireCaractere()
{
    char caractere = getchar();
    while (getchar()!='\n');
    return toupper(caractere);
}

void testCaractere(char caractereEntre, char *motSecret, int *rangs)
{
    int i;
    for (i=0;i<strlen(motSecret);i++)
    {
        if (caractereEntre==motSecret[i]) rangs[i]=1;
    }
}

int testGagne(char *motSecret, int *rangs)
{
    int i, b=1;
    for (i=0;i<strlen(motSecret);i++)
    {
        if (rangs[i]==0) b=0;
    }
    return b;
}
