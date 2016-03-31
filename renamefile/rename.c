#include <stdio.h>
#include <stdlib.h>

int renommer()
{
    if (rename("./fichier.txt", "fichier.doc")!=0)
        printf("Erreur de renommager.\n");
    return EXIT_SUCCESS;
}
