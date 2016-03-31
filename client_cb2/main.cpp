#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include "mpm_client.h"
#include "astar.h"
#include <iostream>

using namespace std;

typedef struct {
	COORD pos;
	mpm_etat_pion_t etat;
} mpm_action_t;

void mpm_process(int joueur_id, mpm_t_lite info_joueurs, int terrain[20][20], mpm_action_t *p_action1, mpm_action_t *p_action2);
void mpm_net_send(SOCKET sock, void *data, int len);
void mpm_net_recv(SOCKET sock, void *data, int len);

int main()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
        fprintf(stderr, "La fonction WSAStartup a echoue.\n");
    else
    {
        SOCKET s;

        s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (s == INVALID_SOCKET)
            fprintf(stderr, "La fonction socket a echoue.\n");
        else
        {
            SOCKADDR_IN server;

            server.sin_family       = AF_INET;
            server.sin_addr.s_addr  = inet_addr("127.0.0.1");
            server.sin_port         = htons(5050);
            memset(&server.sin_zero, '\0', sizeof(server.sin_zero));

            if (connect(s, (SOCKADDR *)&server, sizeof(server)) == SOCKET_ERROR)
                fprintf(stderr, "La fonction connect a echoue.\n");
            else
            {
                int terrain[20][20];
				int joueur_id;

				mpm_action_t action1 = {{-1, -1}, mpm_etat_pion_t(-1)}, action2 = {{-1, -1}, mpm_etat_pion_t(-1)};
				//mpm_action_t action1 = {-1, -1, -1}, action2 = {-1, -1, -1};
				mpm_t_lite info_joueurs;

                while (!_kbhit()) {
					mpm_net_recv(s, terrain, sizeof(terrain));
					mpm_net_recv(s, &joueur_id, sizeof(joueur_id));
					mpm_net_recv(s, &info_joueurs, sizeof(info_joueurs));

					mpm_process(joueur_id, info_joueurs, terrain, &action1, &action2);
					mpm_net_send(s, &action1, sizeof(action1));
					printf("Action 1 sent: %d, %d, %d\n", action1.pos.X, action1.pos.Y, action1.etat);
					mpm_net_send(s, &action2, sizeof(action2));
					printf("Action 2 sent: %d, %d, %d\n\n", action2.pos.X, action2.pos.Y, action2.etat);
				}

                shutdown(s, SD_SEND);
            }

            closesocket(s);
        }

        WSACleanup();
    }

    return 0;
}

COORD get_case_libre(int terrain[20][20])
{
    COORD libre;
    do
    {
        libre.X=rand()%20;
        libre.Y=rand()%20;
    }
    while (terrain[libre.X][libre.Y] != 0);
    return libre;
}

bool pointInListe(point A, list<point>&liste)
{
    list<point>::iterator it;
    for (it=liste.begin();it!=liste.end();it++)
        if (it->x==A.x && it->y==A.y)
            return true;
    return false;
}

list<point>getListeObjets(int carte[20][20])
{
    list<point>listeObjets;
    point actuel;

    int i, j;
    for (i=0;i<20;i++)
    {
        for (j=0;j<20;j++)
        {
            if (carte[i][j]==MPM_ARME || carte[i][j]==MPM_POUVOIR_DESARMEMENT)
            {
                actuel.x = j;
                actuel.y = i;
                if (!pointInListe(actuel, listeObjets))
                    listeObjets.push_back(actuel);
            }
        }
    }
    list<point>::iterator it;
    for (it=listeObjets.begin();it!=listeObjets.end();it++)
    {
        if (carte[it->y][it->x]!=MPM_ARME && carte[it->y][it->x]!=MPM_POUVOIR_DESARMEMENT)
        {
            listeObjets.erase(it);
        }
    }
    return listeObjets;
}

point plusPretObjet(point positionActuel, list<point>listeObjets)
{
    list<point>::iterator it;
    point meilleur = listeObjets.front();
    for (it=listeObjets.begin();it!=listeObjets.end();it++)
    {
        if (distance(positionActuel.x, positionActuel.y, it->x, it->y)<distance(positionActuel.x, positionActuel.y, meilleur.x, meilleur.y))
            meilleur = *it;
    }
    return meilleur;
}

void afficherListe(list<point>listeObjets)
{
    list<point>::iterator it;
    for (it=listeObjets.begin();it!=listeObjets.end();it++)
    {
        cout << "(" << it->x << ", " << it->y << ")" << endl;
    }
}

void majChemin(list<point>&chemin, int carte[20][20], point A, point newTarget)
{
    chemin=trouver_chemin(A, newTarget, carte);
}

bool inCarteTarget(int carte[20][20], point target)
{
    if (carte[target.x][target.y]==MPM_ARME || carte[target.x][target.y]==MPM_POUVOIR_DESARMEMENT)
        return true;
    return false;
}

bool thereIsPrecious(int carte[20][20])
{
    int i, j;
    for (i=0;i<20;i++)
    {
        for (j=0;j<20;j++)
        {
            if (carte[i][j]==MPM_ARME || carte[j][i]==MPM_POUVOIR_DESARMEMENT)
            {
                return true;
            }
        }
    }
    return false;
}

point getArmePos(int carte[20][20])
{
    point armePos;
    int i, j;
    for (i=0;i<20;i++)
    {
        for (j=0;j<20;j++)
        {
            if (carte[j][i]==MPM_ARME || carte[j][i]==MPM_POUVOIR_DESARMEMENT)
            {
                armePos.x = i;
                armePos.y = j;
                return armePos;
            }
        }
    }
}

//list<point>chemin;
//list<point>listeObjets;

bool targetOn = false;

void mpm_process(int joueur_id, mpm_t_lite info_joueurs, int terrain[20][20], mpm_action_t *p_action1, mpm_action_t *p_action2)
{
	point origine;
	point target;
    origine.x = info_joueurs.joueur[joueur_id].pion[0].pos.X;
    origine.y = info_joueurs.joueur[joueur_id].pion[0].pos.Y;
    target.x = 9;
    target.y = 0;

    // Recherche du chemin de origine vers target
    static list<point>chemin = trouver_chemin(origine, target, terrain);
    list<point>listeObjets = getListeObjets(terrain);
    if (!listeObjets.empty())
    {
        cout << "Liste objets : " << endl;
        afficherListe(listeObjets);
        cout << "Objet plus pret : (" << plusPretObjet(origine, listeObjets).x << ", " << plusPretObjet(origine, listeObjets).y << ")" << endl;
    }
    if (!chemin.empty())
    {
        int x, y;
        x = chemin.front().x;
        y = chemin.front().y;
        chemin.pop_front();
        p_action1->pos.X = x;
        p_action1->pos.Y = y;
    }
    else {
        p_action1->pos.X = info_joueurs.joueur[joueur_id].pion[0].pos.X;
        p_action1->pos.Y = info_joueurs.joueur[joueur_id].pion[0].pos.Y;
    }

    p_action1->etat = MPM_PION_ETAT_COURANT;

	p_action2->pos.X = info_joueurs.joueur[joueur_id].pion[1].pos.X;
	p_action2->pos.Y = info_joueurs.joueur[joueur_id].pion[1].pos.Y;
	p_action2->etat = MPM_PION_ETAT_COURANT;

}

void mpm_net_send(SOCKET sock, void *data, int len)
{
	int ret, sent = 0;

	while (len > 0) {
		ret = send(sock, (char *)data + sent, len, 0);
		sent += ret;
		len -= ret;
	}
}

void mpm_net_recv(SOCKET sock, void *data, int len)
{
	int ret, read = 0;

	while (len > 0) {
		ret = recv(sock, (char *)data + read, len, 0);
		read += ret;
		len -= ret;
	}
}
