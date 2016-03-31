#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste* initialiser();
void ajouterElement(Liste *liste, int nombre);
void supprimerPremierElement(Liste *liste);
void afficherListe(Liste *liste);

#endif // LISTE_CHAINEE_H_INCLUDED
