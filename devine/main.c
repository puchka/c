#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fin=25, reponse=0, debut=0;
    do
    {
        printf("Le nombre est-il superieur a %d? ", (debut+fin)/2);
        scanf("%d", &reponse);
        if (reponse)
        {
            debut = (debut+fin)/2;
        }
        else
        {
            fin = (debut+fin)/2;
        }
    }while (debut!=fin-1);
    printf("Le nombre est %d.\n", fin);
    return 0;
}
