#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *fichier_image = NULL;
    int i, j, rayon, width, height;
    double n = 0, pourcent;
    char infos[100];
    char wh[20];
    char *donnees;
    fichier_image = fopen("circle.ppm", "w");
    if (fichier_image!=NULL){
        //printf("Fichier image ouvert avec succès.\n");
        printf("Entrez le rayon du cercle à créer : ");
        scanf("%d", &rayon);
        printf("Pourcentange : ");
        scanf("%lf", &pourcent);
        width = 2*rayon;
        height = width;
        sprintf(wh, "%d\n%d\n255\n", width, height);    // taille de l'image + valeur max
        strcpy(infos, "P3\n");                          // nombre magique (ASCII)
        strcat(infos, wh);
        fprintf(fichier_image, infos);                  // ajout des infos dans le fichier
        donnees = malloc(13*width*height*sizeof(char));
        for (i=0;i<height;i++)
        {
            for (j=0;j<width;j++)
            {
                if (sqrt(pow(i-rayon, 2)+pow(j-rayon, 2))<=rayon)
                {
                    n++;
                }
            }
        }
        pourcent = (pourcent/100)*n;
        n=0;
        for (i=0;i<height;i++)
        {
            for (j=0;j<width;j++)
            {
                if (sqrt(pow(i-rayon, 2)+pow(j-rayon, 2))<=rayon)
                {
                    if (n<pourcent)
                    {
                        if (j<width-1)
                            strcat(donnees, "000 000 255 ");
                        else
                            strcat(donnees, "000 000 255\n");
                    }
                    else
                    {
                        if (j<width-1)
                            strcat(donnees, "000 255 000 ");
                        else
                            strcat(donnees, "000 255 000\n");
                    }
                    n++;
                }
                else
                {
                    if (j<width-1)
                        strcat(donnees, "255 255 255 ");
                    else
                        strcat(donnees, "255 255 255\n");
                }
            }
        }
        fputs(donnees, fichier_image);
        free(donnees);
        fclose(fichier_image);
        printf(">> cicle.ppm\n");
        system("start circle.ppm");
    }
    else
        printf("Erreur lors de l'ouveture du fichier image.\n");
    return EXIT_SUCCESS;
}
