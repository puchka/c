#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char lireCaractere();
void testCaractere(char caractereEntre, char *motSecret, int *rangs);
int testGagne(char *motSecret, int *rangs);
char *lireMot(const char *nomFichier);

int main()
{
    const int nombreDeCoupsMax = 10;
    char *motSecret = lireMot("mots.txt");
    printf("%s",motSecret);
    printf("%d",strlen(motSecret));
    int *rangs = NULL;
    rangs = malloc(sizeof(int)*strlen(motSecret));
    if (rangs==NULL)
    {
        exit(0);
    }
    int i, j;
    for (i=0;i<strlen(motSecret);i++)
    {
        rangs[i] = 0;
    }
    printf("Bienvenu dans le jeu de Pendu!\n");
    i=0;
    int c=1;
    while (i<nombreDeCoupsMax && c)
    {
        printf("\nIl vous reste %d coups.\n", nombreDeCoupsMax-i);
        printf("\nQuel est le mot? ");
        for (j=0;j<strlen(motSecret);j++)
        {
            if (rangs[j]==0) printf("%c",'*');
            else printf("%c",motSecret[j]);
        }
        printf("\nEntrez une lettre : ");
        char caractereEntre=lireCaractere();
        testCaractere(caractereEntre, motSecret, rangs);
        if (testGagne(motSecret, rangs))
        {
            printf("\nVous avez trouve, le mot est : %s", motSecret);
            c=0;
        }
        i++;
    }
    if (i==nombreDeCoupsMax) printf("\n ** Vous etes pendu! **\nLe mot etait : %s", motSecret);
    free(rangs);
    return 0;
}

char lireCaractere()
{
    char caractere = getchar();
    while (getchar()!='\n');
    return toupper(caractere);
}

void testCaractere(char caractereEntre, char *motSecret, int *rangs)
{
    int i;
    for (i=0;i<strlen(motSecret);i++)
    {
        if (caractereEntre==motSecret[i]) rangs[i]=1;
    }
}

int testGagne(char *motSecret, int *rangs)
{
    int i, b=1;
    for (i=0;i<strlen(motSecret);i++)
    {
        if (rangs[i]==0) b=0;
    }
    return b;
}

char *lireMot(const char *nomFichier)
{
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r");
    if (fichier == NULL) exit(0);
    // compter le nombre de mots (lignes)
    char car = fgetc(fichier);
    int nombreDeLignes = 0;
    while (car!=EOF)
    {
        if (car=='\n') nombreDeLignes++;
        car = fgetc(fichier);
    }
    int MIN = 1, MAX = nombreDeLignes;
    srand(time(NULL));
    int ligneMotSecret = (rand()%(MAX-MIN+1))+MIN;
    rewind(fichier);
    int i;
    char motSecret[100] = "";
    for (i=0;i<ligneMotSecret;i++)
    {
        fgets(motSecret,100,fichier);
    }
    fclose(fichier);
    printf("%s",motSecret);
    printf("%d",strlen(motSecret));
    return motSecret;
}
