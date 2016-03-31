#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

int main()
{
    Liste *liste = initialiser();
    ajouterElement(liste, 13);
    supprimerPremierElement(liste);
    afficherListe(liste);
    return 0;
}
