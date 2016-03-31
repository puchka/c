#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main()
{
    File *file = malloc(sizeof(*file));
    enfiler(file, 4);
    enfiler(file, 8);
    enfiler(file, 15);
    enfiler(file, 16);
    enfiler(file, 23);
    enfiler(file, 42);
    afficherFile(file);
    printf("\nJe defile %d\n", defiler(file));
    printf("\nJe defile %d\n", defiler(file));
    afficherFile(file);
    return 0;
}
