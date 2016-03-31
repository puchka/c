#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("=== Menu ===\n");
    printf("1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\n");
    printf("Votre choix ? ");
    int choix;
    scanf("%d", &choix);
    printf("\n");
    switch(choix)
    {
        case 1:
        printf("Vous avez choisi : Royal Cheese.\n");
        break;
        case 2:
        printf("Vous avez choisi : Mc Deluxe.\n");
        break;
        case 3:
        printf("Vous avez choisi : Mc Bacon.\n");
        break;
        case 4:
        printf("Vous avez choisi : Big Mac.\n");
        break;
        default:
        printf("Vous avez choisi n'importe quoi!\n");
    }
    return 0;
}
