#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

void empiler(Pile *pile, int nombre)
{
    if (pile==NULL)
        exit(EXIT_FAILURE);

    Element *nouveau = NULL;
    nouveau = malloc(sizeof(*nouveau));
    if (pile==NULL || nouveau==NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nombre;
    nouveau->suivant = pile->sommet;
    pile->sommet = nouveau;
}

int depiler(Pile *pile)
{
    if (pile==NULL)
        exit(EXIT_FAILURE);

    int nombreSommet = 0;
    Element *sommetActuel = pile->sommet;
    nombreSommet = sommetActuel->nombre;
    pile->sommet = sommetActuel->suivant;
    free(sommetActuel);
    return nombreSommet;
}

void afficherPile(Pile *pile)
{
    if (pile==NULL)
        exit(EXIT_FAILURE);

    Element *sommetActuel = pile->sommet;
    while (sommetActuel!=NULL)
    {
        printf("%d\n", sommetActuel->nombre);
        sommetActuel = sommetActuel->suivant;
    }
}
