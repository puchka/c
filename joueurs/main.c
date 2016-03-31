#include <stdio.h>
#include <stdlib.h>

typedef struct Personne Personne;

struct Personne
{
    char *nom[100];
    char *prenom[100];
};

int main()
{
    Personne joueurs[2];
    int i;
    for (i=0;i<2;i++)
    {
        printf("Entrez le nom du joueur n° %d : \n", i+1);
        scanf("%s", joueurs[i].nom);
        printf("Entrez le prenom du joueur n° %d :\n", i+1);
        scanf("%s", joueurs[i].prenom);
    }
    for (i=0;i<2;i++)
    {
        printf("Le joueur n° %d s'appelle %s %s\n", i+1, joueurs[i].nom, joueurs[i].prenom);
    }
    return 0;
}
