#include <stdio.h>
#include <stdlib.h>

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);

int main()
{
    int tableau1[3]={1,2,3};
    int tableau2[3];
    copie(tableau1,tableau2,3);
    int i;
    for (i=0;i<3;i++)
    {
        printf("%d\n",tableau2[i]);
    }
    return 0;
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
    int i;
    for (i=0;i<tailleTableau;i++)
    {
        tableauCopie[i]=tableauOriginal[i];
    }
}
