#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void enfiler(File *file, int nombre)
{
    if (file==NULL)
        exit(EXIT_FAILURE);

    Element *nouveau = malloc(sizeof(*nouveau));
    nouveau->nombre = nombre;
    nouveau->suivant = NULL;
    if (file->premier==NULL)
    {
        file->premier = nouveau;
    }
    else
    {
        Element *elementActuel = file->premier;
        while (elementActuel->suivant!=NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
}

int defiler(File *file)
{
    int nombre;
    if (file==NULL)
        exit(EXIT_FAILURE);
    Element *premierActuel = file->premier;
    if (premierActuel!=NULL)
    {
        nombre = premierActuel->nombre;
        file->premier = premierActuel->suivant;
        free(premierActuel);
    }
    return nombre;
}

void afficherFile(File *file)
{
    if (file==NULL)
        exit(EXIT_FAILURE);
    Element *elementActuel = file->premier;
    while (elementActuel!=NULL)
    {
        printf("%d ", elementActuel->nombre);
        elementActuel = elementActuel->suivant;
    }
}
