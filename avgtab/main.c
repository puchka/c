#include <stdio.h>
#include <stdlib.h>

double moyenneTableau(int tableau[], int tailleTableau);

int main()
{
    int tableau[4]={1,2,3,4};
    printf("%f\n", moyenneTableau(tableau,4));
    system("PAUSE");
    return 0;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
    int i;
    double somme=0;
    for (i=0;i<tailleTableau;i++)
    {
        somme+=tableau[i];
    }
    return somme/tailleTableau;
}
