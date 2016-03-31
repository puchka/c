#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include "mpm_client.h"
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

void mpm_process(int joueur_id, mpm_t_lite info_joueurs, int terrain[20][20], mpm_action_t *p_action1, mpm_action_t *p_action2)
{
	if (joueur_id == 0) {
		info_joueurs.joueur[0].pion[0].pos.X = 0;
		info_joueurs.joueur[0].pion[0].pos.Y++;
		p_action1->pos = info_joueurs.joueur[0].pion[0].pos;

		info_joueurs.joueur[0].pion[1].pos.X = 18;
		info_joueurs.joueur[0].pion[1].pos.Y++;
		p_action2->pos = info_joueurs.joueur[0].pion[1].pos;
	} else {
	}

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


