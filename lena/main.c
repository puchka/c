#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialisations
    int n = 0;      // n : nombre d'infos récuperées
    char line[100]; // stockage de la ligne récupérée
    char type[100]; // type P2 ou P5
    int w = 0;      // largeur de l'image
    int h = 0;      // hauteur de l'image
    int max = 0;    // valeur maximal d'un pixel
    int l = 0;      // longueur des infos
    int i, j;             // variable de boucle
    int i_, j_;
    int somme = 0;
    int matrix[512][512] = {0};
    int matrix2[256][256];
    unsigned char matrix3[512][512];
    unsigned char *buffer2 = malloc(256*256*sizeof(unsigned char));
    unsigned char *buffer3 = malloc(512*512*sizeof(unsigned char));
    int size_data = 0; // taille du buffer
    FILE *fichier_dest = NULL;
    char entete[100];
    // --  Extraire les informations dans le fichier --
    // Ouverture du fichier image en mode texte
    FILE *fichier_image = NULL;
    fichier_image = fopen("lena512.pgm", "r");
    if (fichier_image != NULL)
    {
        printf("Fichier ouvert!\n");
        while (n<3)
        {
            fgets(line, 100, fichier_image);
            l+=strlen(line);
            if (line[0]!='#')
            {
                if (n==0)
                {
                    strcpy(type, line);
                }
                else if (n==1)
                {
                    sscanf(line, "%d %d", &w, &h);
                }
                else if (n==2)
                {
                    max = strtol(line, NULL, 10);
                }
                n++;
            }
        }
        fclose(fichier_image);
        printf("Type : %s", type);
        printf("Width : %d\n", w);
        printf("Height : %d\n", h);
        printf("Valeur max : %d\n", max);
        printf("Longueur : %d\n", l);
    }
    else
        printf("Erreur lors de l'ouverture du fichier image.\n");
    // -- Mettre les données l'image dans un buffer --
    fichier_image = NULL;
    fichier_image = fopen("lena512.pgm", "rb");
    if (fichier_image != NULL)
    {
        printf("Fichier ouvert en mode binaire!\n");
        fseek(fichier_image, l, SEEK_SET);
        size_data = w*h*sizeof(unsigned char);
        unsigned char *buffer = malloc(size_data);
        fread(buffer, sizeof(unsigned char), size_data, fichier_image);
        printf("Données copiés dans le buffer!\n");
        printf("Taille buffer : %d\n", size_data);
        for (i=0;i<w;i++)
        {
            for (j=0;j<h;j++)
            {
                matrix[i][j] = buffer[512*i+j];
            }
        }
        // Réduction de la taille de l'image en 2
        for (i=0;i<512;i+=2)
        {
            for (j=0;j<512;j+=2)
            {
                somme = 0;
                for (i_=i;i_<i+2;i_++)
                {
                    for (j_=j;j_<j+2;j_++)
                    {
                        somme += matrix[i_][j_];
                    }
                }
                matrix2[i/2][j/2] = somme/4;
            }
        }
        for (i=0;i<256;i++)
        {
            for (j=0;j<256;j++)
            {
                buffer2[256*i+j]=matrix2[i][j];
            }
        }
        fichier_dest = fopen("lena256.pgm", "w");
        if (fichier_dest != NULL)
        {
            printf("Fichier dest ouvert!\n");
            // Insérer les en-têtes
            strcpy(entete, "P5\n256 256\n255\n");
            fputs(entete, fichier_dest);
            fwrite(buffer2, sizeof(unsigned char), 256*256*sizeof(unsigned char), fichier_dest);
            fclose(fichier_dest);
        }
        else
            printf("Erreur lors de l'ouverture du fichier dest.\n");
        // Rotation
        ///*
        for (i=0;i<512;i++)
        {
            for (j=0;j<512;j++)
            {
                matrix3[i][j] = matrix[j][i];
            }
        }
        ///*
        for (i=0;i<512;i++)
        {
            for (j=0;j<512;j++)
                buffer3[512*i+j] = matrix3[i][j];
        }
        FILE *fichier_dest2 = NULL;
        fichier_dest2 = fopen("lena512_.pgm", "w");
        if (fichier_dest2 != NULL)
        {
            printf("Fichier dest ouvert!\n");
            // Insérer les en-têtes
            strcpy(entete, "P5\n512 512\n255\n");
            fputs(entete, fichier_dest);
            fwrite(buffer3, sizeof(char), 512*512, fichier_dest2);
            fclose(fichier_dest2);
        }
        else
            printf("Erreur lors de l'ouverture du fichier dest.\n");
        //*/
        fclose(fichier_image);
    }
    else
        printf("Erreur lors de l'ouverture du fichier en mode binaire.\n");
    return EXIT_SUCCESS;
}
