#include <stdlib.h>
#include <gtk/gtk.h>
#include"calcul.h"
void Arithmetique (GtkWidget *pEntry, gpointer data);
void Geometrique(GtkWidget *pEntry,gpointer data);
void Reset(GtkWidget *pEntry, gpointer data);



struct _MainWindow
    {
    GtkWidget *pWindow;
    GtkWidget *pTable;
    GtkWidget *pLabel0;
    GtkWidget *pLabel1;
    GtkWidget *pLabel2;
    GtkWidget *plabel3;
    GtkWidget *plabel4;
    GtkWidget *pEntry1;
    GtkWidget *pEntry2;
    GtkWidget *pEntry3;
    GtkWidget *pEntry4;
    GtkWidget *pButton1;
    GtkWidget *pButton2;
    GtkWidget *pButton3;
    };

typedef struct _MainWindow MainWindow;
int main (int argc, char *argv[])
{
    gtk_init(& argc, &argv);
    MainWindow *pApp;
    pApp=g_malloc(sizeof(MainWindow));

    /*GtkWidget *pVBox;
    GtkWidget *pHbox1;
    GtkWidget *pHBox2;
    GtkWidget *pHbox3;*/

    //Definition de la fenetre
    pApp->pWindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(pApp->pWindow),320,200);

    //insertion du tableau dans la fenetre
    gtk_window_set_title(GTK_WINDOW(pApp->pWindow)," CALCUL SUITE NUMERIQUE");

    //Creation du tableau
    pApp->pTable = gtk_table_new(4,4,TRUE);
    gtk_container_add(GTK_WINDOW(pApp->pWindow),pApp->pTable);

    //definition des labels
    pApp->pLabel0 = gtk_label_new("Veuillez entrez trois parametres,puis choisissez le nature de la suite pour chercher l'inconnu\n");
    pApp->pLabel1=gtk_label_new("Uo");
    pApp->pLabel2=gtk_label_new("raison");
    pApp->plabel3=gtk_label_new("n");
    pApp->plabel4=gtk_label_new("Un");

    //definition des zones de saisie
    pApp->pEntry1=gtk_entry_new();
    pApp->pEntry2=gtk_entry_new();
    pApp->pEntry3=gtk_entry_new();
    pApp->pEntry4=gtk_entry_new();

    //definition des boutons
    pApp->pButton1=gtk_button_new_with_label("Arithmetique");
    pApp->pButton2=gtk_button_new_with_label("Geometrique");
    pApp->pButton3=gtk_button_new_with_label("Reset");

    //placement des widget dans le tableau
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pLabel0,0,4,0,1);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pLabel1,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pLabel2,0,1,2,3);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->plabel3,2,3,1,2);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->plabel4,2,3,2,3);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pEntry1,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pEntry2,3,4,1,2);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pEntry3,1,2,2,3);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pEntry4,3,4,2,3);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pButton1,0,1,3,4);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pButton2,1,2,3,4);
    gtk_table_attach_defaults(GTK_TABLE(pApp->pTable),pApp->pButton3,2,4,3,4);


    //boutton arithmetique
    g_signal_connect(G_OBJECT(pApp->pButton1),"clicked",G_CALLBACK(Arithmetique),(gpointer)pApp);
    g_signal_connect(G_OBJECT(pApp->pButton2),"clicked",G_CALLBACK(Geometrique),(gpointer)pApp);
    g_signal_connect(G_OBJECT(pApp->pButton3),"clicked",G_CALLBACK(Reset),(gpointer)pApp);

    g_signal_connect(G_OBJECT(pApp->pWindow),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(pApp->pWindow);
    gtk_main();
    g_free(pApp);
    return EXIT_SUCCESS;
}
void Arithmetique(GtkWidget *pEntry,gpointer data)
{
    gfloat Uo;
    gfloat raison;
    gint n;
    gfloat Un,a;
    gfloat resultat;//pour prendre une valeur float
    gint resultat1,k,r;//pour prendre une valeur int
    gchar temp[40];
    MainWindow *pApp;
    pApp=(MainWindow*) data;


    Uo=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry1)));
    raison=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry3)));
    n=atoi(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry2)));
    Un=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry4)));
    if(Un==0)
    {
        resultat=Uo+(n*raison);
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry4),temp);
    }
    else if(Uo==0)
    {
        resultat=Un-(n*raison);
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry1),temp);
    }
    else if(raison==0)
    {
        resultat=(Un-Uo)/n;
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry3),temp);
    }
    else if(n==0) //mbol ketreana
    {
        resultat=(Un-Uo)/raison;
        k=(Un-Uo);
        r=raison;
        resultat1=k/r;
        a=(Un-Uo)-(raison*resultat1);
        if(a==0)
        {
            sprintf(temp,"%f",resultat);
            gtk_entry_set_text(GTK_ENTRY(pApp->pEntry2),temp);
        }
        else if(a!=0)
        {
            gtk_entry_set_text(GTK_ENTRY(pApp->pEntry2),"erreur");
        }
    }
}




void Geometrique(GtkWidget *pEntry,gpointer data)
{
    gfloat Uo;
    gfloat raison;
    gint n;
    gfloat Un,a;// a est un nombre utiliser pour la racine n ieme
    gdouble resultat;
    gfloat b,c;//pour prendre une valeur float
    gint resultat1,k,r;//pour prendre une valeur int
    gchar temp[40];
    MainWindow *pApp;
    pApp=(MainWindow*) data;


    Uo=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry1)));
    raison=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry3)));
    n=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry2)));
    Un=atof(gtk_entry_get_text(GTK_ENTRY(pApp->pEntry4)));
    if(Un==0) //recherche de Un
    {
        resultat=Uo*pow(raison,n);
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry4),temp);
    }
    else if(Uo==0)// recherche de Uo
    {
        resultat=Un/pow(raison,n);
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry1),temp);
    }
    else if(raison==0) //recherche de raison
    {
        a=1.0/n;
        resultat=pow((Un/Uo),a);
        sprintf(temp,"%f",resultat);
        gtk_entry_set_text(GTK_ENTRY(pApp->pEntry3),temp);
    }
    else if(n==0) //recherche de n  fa mbol ketreana
    {
        b=(Un/Uo);

        resultat=log(b)/log(raison);
        resultat1=(int)(resultat);
        a=resultat-resultat1;
        if(a==0)
        {
            sprintf(temp,"%f",resultat);
            gtk_entry_set_text(GTK_ENTRY(pApp->pEntry2),temp);
        }
        else if(resultat1!=0)
        {
            gtk_entry_set_text(GTK_ENTRY(pApp->pEntry2),"erreur");
        }
    }
}

void Reset(GtkWidget *pEntry, gpointer data)
{
    MainWindow *pApp;
    pApp=(MainWindow*) data;
    gtk_entry_set_text(GTK_ENTRY(pApp->pEntry1),NULL);
    gtk_entry_set_text(GTK_ENTRY(pApp->pEntry2),NULL);
    gtk_entry_set_text(GTK_ENTRY(pApp->pEntry3),NULL);
    gtk_entry_set_text(GTK_ENTRY(pApp->pEntry4),NULL);
}
