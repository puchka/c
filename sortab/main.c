#include <stdio.h>
#include <stdlib.h>

void ordonnerTableau(int tableau[], int tailleTableau);

int main()
{
    int tableau[4]={3,1,2,4};
    ordonnerTableau(tableau, 4);
    int i;
    for (i=0;i<4;i++)
    {
        printf("%d\n",tableau[i]);
    }
    return 0;
}

void ordonnerTableau(int tableau[], int tailleTableau)
{
    int i, j, tmp;
    for (i=0;i<tailleTableau;i++)
    {
        for (j=0;j<tailleTableau;j++)
        {
            if (tableau[j]>tableau[i])
            {
                tmp=tableau[i];
                tableau[i]=tableau[j];
                tableau[j]=tmp;
            }
        }
    }
}
