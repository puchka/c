#include <windows.h>
#include <winbase.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int OuvrirCom();
int FermerCom();

// VARIABLES GLOBALES
//-----------------------------------------------------------------------------

DCB g_DCB; // structure dcb du port
HANDLE g_hCom = 0; // handle de la com

int main()
{
    char c='0';
    while (1)
    {
        scanf("%c", &c);
        if (c=='q')
            break;
        if (c=='A')
        {
            OuvrirCom();
            printf("Port ouvert!");
        }
        else if (c=='Z')
        {
            FermerCom();
            printf("Port fermé!");
        }
    }
    return 0;
}

int OuvrirCom()
{
  // On ouvre le port série
  g_hCom = CreateFile( "COM1", GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_FLAG_WRITE_THROUGH | FILE_FLAG_NO_BUFFERING,NULL);

  if(g_hCom == INVALID_HANDLE_VALUE)
  {
        return FALSE ;
  }
  else
  {
    // on vide les tampons d'émission et de réception, mise à 1 DTR
    PurgeComm( g_hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);

    // On paramètre le port série
    g_DCB.DCBlength = sizeof(DCB);

    //Configuration actuelle
    GetCommState(g_hCom, &g_DCB);

    //Modification du DCB
    g_DCB.BaudRate = 9600 ;
    g_DCB.ByteSize = 8;

    g_DCB.fDtrControl = DTR_CONTROL_ENABLE; // (DISABLE)
        // Gestion de la parité parmi

        g_DCB.Parity = NOPARITY;

        // Gestion du Stop Bit
        g_DCB.StopBits = ONESTOPBIT;

        //Configuration de la liaison serie
        SetCommState(g_hCom, &g_DCB);

        return TRUE ;
    }
}

int FermerCom()
{
   if(g_hCom!=NULL)
   {
      CloseHandle(g_hCom);
      return TRUE ;
   }
}

/*
int EnvoyerCom(char* Chaine)
{
   DWORD NumBytes=0;
   int TailleChaine = strlen(Chaine) ;
   printf("\n Taille de la chaine : %d \n", TailleChaine) ;

   if(g_hCom != NULL)
   {
      //Emission de la Chaine
      if  (WriteFile(g_hCom,Chaine, TailleChaine,&NumBytes,NULL)==0)
      {
         printf ("\n Erreur emission.\n") ;
         return FALSE ;
      }
      else
      {
         printf("\n Chaine envoyee : %s.\n", Chaine) ;
         return TRUE ;
      }
   }
   else
      return FALSE ;
}
*/
