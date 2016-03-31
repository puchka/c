#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *sommet;
};

void empiler(Pile *pile, int nombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);

#endif // PILE_H_INCLUDED
