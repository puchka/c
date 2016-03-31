#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

Liste* initialiser()
{
    Liste *liste = NULL;
    liste = malloc(sizeof(*liste));
    Element *element = NULL;
    element = malloc(sizeof(*element));
    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    return liste;
}

void ajouterElement(Liste *liste, int nombre)
{
    Element *nouveau = NULL;
    nouveau = malloc(sizeof(*nouveau));
    nouveau->nombre = nombre;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void supprimerPremierElement(Liste *liste)
{
    Element *premierActuel = NULL;
    premierActuel = liste->premier;
    liste->premier = premierActuel->suivant;
    free(premierActuel);
}

void afficherListe(Liste *liste)
{
    Element *elementActuel = NULL;
    elementActuel = liste->premier;
    while (elementActuel!=NULL)
    {
        printf("%d\n", elementActuel->nombre);
        elementActuel = elementActuel->suivant;
    }
}
