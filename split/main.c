#include <stdio.h>
#include <stdlib.h>

int main()
{
    char chaine[100];
    char *debut;
    char *fin;
    strcpy(chaine, "Hello world!\n");
    debut = strtok(chaine, " ");
    fin = strtok(NULL, " w");
    printf("%s\n", debut);
    printf("%s", fin);
    return 0;
}
