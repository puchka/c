#include "astar.h"
#include "mpm_client.h"

using namespace std;

l_noeud liste_ouverte;
l_noeud liste_fermee;
noeud depart;
struct point arrivee;

list<point> trouver_chemin(point A, point B, int carte[20][20])
{
    list<point> chemin;
    depart.parent.first  = 0;
    depart.parent.second = 0;
    arrivee.x = B.x;
    arrivee.y = B.y;
    pair <int, int> courant;
    courant.first  = A.x;
    courant.second = A.y;
    liste_ouverte[courant]=depart;
    ajouter_liste_fermee(courant);
    ajouter_cases_adjacentes(courant, carte);
    while( !((courant.first == arrivee.x) && (courant.second == arrivee.y))
            &&
           (!liste_ouverte.empty())
         ){

        // on cherche le meilleur noeud de la liste ouverte, on sait qu'elle n'est pas vide donc il existe
        courant = meilleur_noeud(liste_ouverte);

        // on le passe dans la liste fermee, il ne peut pas déjà y être
        ajouter_liste_fermee(courant);

        ajouter_cases_adjacentes(courant, carte);
    }

    if ((courant.first == arrivee.x) && (courant.second == arrivee.y)){
        retrouver_chemin(chemin);

    }else{
            /* pas de solution */
            cout << "Il n'y a pas de solution." << endl;
    }

    return chemin;
}

int distance(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void ajouter_cases_adjacentes(pair <int, int>& n, int carte[20][20]){
    noeud tmp;
    point cases_adjacentes[4];
    cases_adjacentes[0].x = n.second;
    cases_adjacentes[0].y = n.first-1;
    cases_adjacentes[1].x = n.second+1;
    cases_adjacentes[1].y = n.first;
    cases_adjacentes[2].x = n.second;
    cases_adjacentes[2].y = n.first+1;
    cases_adjacentes[3].x = n.second-1;
    cases_adjacentes[3].y = n.first;
    for (int i=0;i<4;i++)
    {
        if (cases_adjacentes[i].x<0 || cases_adjacentes[i].x>19)
            continue;
        if (cases_adjacentes[i].y<0 || cases_adjacentes[i].y>19)
            continue;
        if (carte[cases_adjacentes[i].y][cases_adjacentes[i].x]==MPM_MUR)
            continue;
        //cout << "(" << cases_adjacentes[i].x << "," << cases_adjacentes[i].y << ")" << endl;
        pair<int,int> it(cases_adjacentes[i].y, cases_adjacentes[i].x);

        if (!deja_present_dans_liste(it, liste_fermee)){
        /* le noeud n'est pas déjà présent dans la liste fermée */

        tmp.cout = distance(cases_adjacentes[i].y, cases_adjacentes[i].x, n.first, n.second);
        tmp.parent = n;

        if (deja_present_dans_liste(it, liste_ouverte)){
            /* le noeud est déjà présent dans la liste ouverte, il faut comparer les couts */
            if (tmp.cout < liste_ouverte[it].cout){
                /* si le nouveau chemin est meilleur, on update */
                liste_ouverte[it]=tmp;
            }

            /* le noeud courant a un moins bon chemin, on ne change rien */


            }
            else{
                /* le noeud n'est pas présent dans la liste ouverte, on l'ajoute */
                liste_ouverte[pair<int,int>(cases_adjacentes[i].y, cases_adjacentes[i].x)]=tmp;
            }
        }
    }
}

bool deja_present_dans_liste(pair<int,int> n, l_noeud& l){
    l_noeud::iterator i = l.find(n);
    if (i==l.end())
        return false;
    else
        return true;
}

pair<int,int> meilleur_noeud(l_noeud& l){
    int m_cout = l.begin()->second.cout;
    pair<int,int> m_noeud = l.begin()->first;

    for (l_noeud::iterator i = l.begin(); i!=l.end(); i++)
        if (i->second.cout< m_cout){
            m_cout = i->second.cout;
            m_noeud = i->first;
        }

    return m_noeud;
}

void ajouter_liste_fermee(pair<int,int>& p){
    noeud& n = liste_ouverte[p];
    liste_fermee[p]=n;

    // il faut le supprimer de la liste ouverte, ce n'est plus une solution explorable
    if (liste_ouverte.erase(p)==0)
        cerr << "n'apparait pas dans la liste ouverte, impossible à supprimer" << endl;
    return;
}

void retrouver_chemin(list<point>&chemin){
    // l'arrivée est le dernier élément de la liste fermée.
    noeud& tmp = liste_fermee[pair<int, int>(arrivee.x, arrivee.y)];

    struct point n;
    pair<int, int> prec;
    n.x = arrivee.x;
    n.y = arrivee.y;
    prec.first  = tmp.parent.first;
    prec.second = tmp.parent.second;
    chemin.push_front(n);

    while (prec != pair<int,int>(depart.parent.first,depart.parent.first)){
        n.x = prec.first;
        n.y = prec.second;
        chemin.push_front(n);

        tmp = liste_fermee[tmp.parent];
        prec.first  = tmp.parent.first;
        prec.second = tmp.parent.second;
    }
}
