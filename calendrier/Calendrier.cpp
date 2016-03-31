#include <iostream>
#include <string>

using namespace std;

class Calendrier
{
    public:
    Calendrier();
    void LireValeur(int annee, int jour, string mois);
    void afficher();
    void premierJour();
    void alinea();
    void jourParMois();
    void calendrierGregorien();
    void typeDeMois();
    bool erreur();

    private:
    int m_annee;
    int m_jour;
    string m_mois;
    string m_premierJour;
    int m_alinea;
    int m_nbrDeJour_parMois;
};

Calendrier::Calendrier():m_annee(2012), m_jour(8), m_mois("Janvier"),m_premierJour("dimanche"), m_alinea(1)
{

}

void Calendrier::LireValeur(int annee, int jour, string mois)
 {
     cout <<"Entrez jour:" <<endl;
     cin>> jour;
     cout <<"Entrez mois:" <<endl;
     cin >> mois;
     cout <<"Entrez annee:" <<endl;
     cin>>annee;
     m_annee=annee;
     m_jour=jour;
     m_mois=mois;
 }
void Calendrier::afficher()
{
    cout<<"Date entree:"<<m_jour<<" "<<m_mois<<" "<<m_annee<<endl;
    cout<<"Premier jour:\n"<<m_premierJour<<endl<<"Alinea:\n"<<m_alinea<<endl;
    cout<<"il y a: "<<m_nbrDeJour_parMois<<" jour"<<endl;
}
void Calendrier::premierJour()
{
    if (m_annee>1900&&m_annee<=2100)
    {
        if (m_annee%7==1&&m_annee%4==0||m_annee%7==2&&m_annee%4==2||m_annee%7==5&&m_annee%4==3||m_annee%7==6&&m_annee%4==1)
            m_premierJour="Lu";
        else if (m_annee%7==0&&m_annee%4==2||m_annee%7==3&&m_annee%4==3||m_annee%7==4&&m_annee%4==1||m_annee%7==6&&m_annee%4==0)
            m_premierJour="Ma";
        else if (m_annee%7==1&&m_annee%4==3||m_annee%7==2&&m_annee%4==1||m_annee%7==4&&m_annee%4==0||m_annee%7==5&&m_annee%4==2)
            m_premierJour="Me";
        else if (m_annee%7==0&&m_annee%4==1||m_annee%7==2&&m_annee%4==0||m_annee%7==3&&m_annee%4==2||m_annee%7==6&&m_annee%4==3)
            m_premierJour="Je";
        else if (m_annee%7==0&&m_annee%4==0||m_annee%7==1&&m_annee%4==2||m_annee%7==4&&m_annee%4==3||m_annee%7==5&&m_annee%4==1)
            m_premierJour="Ve";
        else if (m_annee%7==2&&m_annee%4==3||m_annee%7==3&&m_annee%4==1||m_annee%7==5&&m_annee%4==0||m_annee%7==6&&m_annee%4==2)
            m_premierJour="Sa";
        else
            m_premierJour="Di";
    }
}

void Calendrier::alinea()
{
    int i;
    string jourDeLaSemaine[7]={"Lu","Ma","Me","Je","Ve","Sa","Di"};
    for (i=0; i<7; i++)
    {
        if (m_premierJour==jourDeLaSemaine[i])
            m_alinea=i;
    }
}
void Calendrier::calendrierGregorien()
{
    int i,j=0;
    cout <<m_mois<<endl<<m_annee<<endl<<endl;
    string jourDeLaSemaine[7]={"Lu","Ma","Me","Je","Ve","Sa","Di"};
    for (i=0; i<7; i++)
    {
        cout<<jourDeLaSemaine[i]<<"\t";
        if (i==6)
        {
            cout <<endl;
        }
    }
    for (i=1; i<=m_nbrDeJour_parMois; i++)
    {
        while (j<m_alinea)
        {
            cout <<"\t";
            j=j+i;
        }
        if (i!=1&&(i+m_alinea-1)%7==0)
            cout<<endl;
        if (i<10)
            cout<<" ";
        if(i==m_jour)
            cout<<i<<"*\t";
        else
            cout<<i<<"\t";
    }
}
void Calendrier::jourParMois()
{
    if (m_mois=="Avril"||m_mois=="Juin"||m_mois=="Septembre"||m_mois=="Novembre"||m_mois=="AVRIL"||m_mois=="JUIN"||m_mois=="SEPTEMBRE"||m_mois=="NOVEMBRE"||m_mois=="avril"||m_mois=="juin"||m_mois=="septembre"||m_mois=="novembre")
        m_nbrDeJour_parMois=30;
    else if (m_mois=="Fevrier"||m_mois=="Février"||m_mois=="FEVRIER"||m_mois=="fevrier"||m_mois=="février")
    {
        if (m_annee%4==0)
            m_nbrDeJour_parMois=29;
        else
            m_nbrDeJour_parMois=28;
    }
    else
        m_nbrDeJour_parMois=31;
}
void Calendrier::typeDeMois()
{
    if (m_annee%4==0)
    {
        if(m_mois=="Janvier"||m_mois=="Avril"||m_mois=="Juillet"||m_mois=="JANVIER"||m_mois=="AVRIL"||m_mois=="JUILLET"||m_mois=="janvier"||m_mois=="avril"||m_mois=="juillet")
        {
            m_alinea==m_alinea;
        }
        else if(m_mois=="Fevrier"||m_mois=="Fúvrier"||m_mois=="Aout"||m_mois=="FEVRIER"||m_mois=="AOUT"||m_mois=="août"||m_mois=="fevrier"||m_mois=="février"||m_mois=="aout"||m_mois=="Août")
        {
            m_alinea=m_alinea-4;
        }
        else if (m_mois=="Mars"||m_mois=="Novembre"||m_mois=="MARS"||m_mois=="NOVEMBRE"||m_mois=="mars"||m_mois=="novembre")
        {
            m_alinea=m_alinea-3;
        }
        else if (m_mois=="Mai"||m_mois=="MAI"||m_mois=="mai")
        {
            m_alinea=m_alinea-5;
        }
        else if(m_mois=="Juin"||m_mois=="JUIN"||m_mois=="juin")
        {
            m_alinea=m_alinea-2;
        }
        else if(m_mois=="Septembre"||m_mois=="Decembre"||m_mois=="Décembre"||m_mois=="SEPTEMBRE"||m_mois=="DECEMBRE"||m_mois=="septembre"||m_mois=="decembre"||m_mois=="décembre")
        {
            m_alinea=m_alinea-1;
        }
        else
            m_alinea=m_alinea-6;
    }
    else
    {
        if(m_mois=="Janvier"||m_mois=="Octobre"||m_mois=="JANVIER"||m_mois=="OCTOBRE"||m_mois=="janvier"||m_mois=="octobre")
        {
            m_alinea==m_alinea;
        }
        else if(m_mois=="Fevrier"||m_mois=="Février"||m_mois=="Mars"||m_mois=="Novembre"||m_mois=="FEVRIER"||m_mois=="MARS"||m_mois=="NOVEMBRE"||m_mois=="fevrier"||m_mois=="février"||m_mois=="mars"||m_mois=="novembre")
        {
            m_alinea=m_alinea-4;
        }
        else if (m_mois=="Avril"||m_mois=="Juillet"||m_mois=="AVRIL"||m_mois=="JUILLET"||m_mois=="avril"||m_mois=="juillet")
        {
            m_alinea=m_alinea-1;
        }
        else if (m_mois=="Mai"||m_mois=="MAI"||m_mois=="mai")
        {
            m_alinea=m_alinea-6;
        }
        else if(m_mois=="Juin"||m_mois=="JUIN"||m_mois=="juin")
        {
            m_alinea=m_alinea-3;
        }
        else if(m_mois=="Septembre"||m_mois=="Decembre"||m_mois=="Décembre"||m_mois=="SEPTEMBRE"||m_mois=="DECEMBRE"||m_mois=="septembre"||m_mois=="decembre"||m_mois=="décembre")
        {
            m_alinea=m_alinea-2;
        }
        else
            m_alinea=m_alinea-5;
    }
    if (m_alinea<0)
        m_alinea=m_alinea+7;
}


bool Calendrier::erreur()
{
    int test=0,i=0,j=0;
    string douze_mois[36]={"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre","JANVIER", "FEVRIER", "MARS", "AVRIL", "MAI", "JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECEMBRE","janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};
    for (i=0; i<36; i++)
    {

        if (m_mois==douze_mois[i])
        {
            test++;
            break;
        }
    }
    if (m_jour>30&&(m_mois=="Avril"||m_mois=="Juin"||m_mois=="Septembre"||m_mois=="Novembre"||m_mois=="AVRIL"||m_mois=="JUIN"||m_mois=="SEPTEMBRE"||m_mois=="NOVEMBRE"||m_mois=="avril"||m_mois=="juin"||m_mois=="septembre"||m_mois=="novembre"))
        test=0;
    if(m_jour>28&&m_annee%4!=0&&(m_mois=="fevrier"||m_mois=="FEVRIER"||m_mois=="Fevrier"))
        test=0;
    if (m_jour>31)
        test=0;
    if (test==0)
    {
        cout<<"Date invalide!!"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
    Calendrier date;
    int entrer_annee, entrer_jour;
    string entrer_mois;
    date.LireValeur(entrer_annee,entrer_jour,entrer_mois);
    while (date.erreur())
    {
        date.premierJour();
        date.alinea();
        date.jourParMois();
        //date.afficher();
        cout <<"*******************************************************************************\n";
        date.typeDeMois();
        date.calendrierGregorien();
        cout <<"\n******************************************************************************\n";
        break;
    }
        cout << endl<<"Hello world!" << endl;
    return 0;
}
