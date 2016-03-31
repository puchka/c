#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_EXPRESSION 100

void eval(const char expression[TAILLE_MAX_EXPRESSION], char result[TAILLE_MAX_EXPRESSION]);

int main()
{
    char expression[TAILLE_MAX_EXPRESSION], result[TAILLE_MAX_EXPRESSION];
    printf("Entrez une expression a evaluer ou quit pour quitter.\n");
    do
    {
        printf(">> ");
        fgets(expression, TAILLE_MAX_EXPRESSION, stdin);
        eval(expression, result);
        printf("%s", result);
    }
    while (strcmp(expression, "quit")!=1);
    return EXIT_SUCCESS;
}

void eval(const char expression[TAILLE_MAX_EXPRESSION], char result[TAILLE_MAX_EXPRESSION])
{
    if (strchr(expression, '='))
    {
        char *variable, *valeur;
        variable = strtok(expression, "=");
        valeur = strtok(NULL, "=");
        strcpy(result, valeur);
    }
    else
        strcpy(result, expression);
}
