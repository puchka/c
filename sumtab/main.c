#include <stdio.h>
#include <stdlib.h>

int sommeTableau(int tableau[], int tailleTableau);

int main()
{
    int tableau[4]={1,2,3,4};
    printf("%d\n",sommeTableau(tableau,4));
    system("PAUSE");
    return 0;
}

int sommeTableau(int tableau[], int tailleTableau)
{
    int i, somme=0;
    for (i=0;i<tailleTableau;i++)
    {
        somme+=tableau[i];
    }
    return somme;
}
