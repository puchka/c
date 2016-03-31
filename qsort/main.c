#include <stdio.h>
#include <stdlib.h>

/* affichage du tableau */
static void aff (int *a, size_t n)
{
   size_t i;
   for (i = 0; i < n; i++)
   {
      printf ("%3d", a[i]);
   }
   printf ("\n");
}

/* fonction utilisateur de comparaison fournie a qsort() */
static int compare (void const *a, void const *b)
{
   /* definir des pointeurs type's et initialise's
      avec les parametres */
   int const *pa = a;
   int const *pb = b;

   /* evaluer et retourner l'etat de l'evaluation (tri croissant) */
   return *pa - *pb;
}

int main (void)
{
    /* tableau a trier */
    int tab[] = { 4, 6, -3, 4, 7 };

    /* affichage du tableau dans l'etat */
    aff (tab, sizeof tab / sizeof *tab);

    qsort (tab, sizeof tab / sizeof *tab, sizeof *tab, compare);

    /* affichage du tableau apres le tri */
    aff (tab, sizeof tab / sizeof *tab);

    return 0;
}
