#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED

#include <iostream>
#include <map>
#include <list>

typedef unsigned char case_t;

struct noeud{
    int cout;
    std::pair<int, int> parent;
};

struct point{
    int x,y;
};

typedef std::map<std::pair<int, int>, noeud> l_noeud;

std::list<point>trouver_chemin(point, point, case_t carte[5][5]);
int distance(int, int, int, int);
void ajouter_cases_adjacentes(std::pair<int, int>&, case_t carte[5][5]);
bool deja_present_dans_liste(std::pair<int, int>, l_noeud&);
std::pair<int, int> meilleur_noeud(l_noeud&);
void ajouter_liste_fermee(std::pair<int, int>&);
void retrouver_chemin(std::list<point>&);

#endif // ASTAR_H_INCLUDED
