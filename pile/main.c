#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int main()
{
    Pile *pile = NULL;
    pile = malloc(sizeof(*pile));
    empiler(pile, 1);
    empiler(pile, 2);
    empiler(pile, 3);
    empiler(pile, 4);
    afficherPile(pile);
    printf("Je depile %d\n", depiler(pile));
    afficherPile(pile);
    return 0;
}
