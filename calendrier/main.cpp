#include <iostream>

// Nombre de jours dans une annee
int nbreJoursAnnee(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0)||(annee % 100 == 0 && annee % 400 ==0))
      return 366;
    else
      return 365;

}

// Nombre de jours entre le premier du mois et le 1er janvier
int nbreJoursMoisAnnee(int mois, int annee)
{
    int nbreJours = 0;
    int finMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (nbreJoursAnnee(annee)==366)
        finMois[1] = 29;
    for(int i=0; i<mois; i++)
        nbreJours+=finMois[i];

    return nbreJours;
}

// Nombre de jour entre le 1er du mois et le 1er janvier 2012
int nbreJoursMoisAnnee2012(int mois, int annee)
{
    int nbreJours = 0;
    if(annee>=2012)
    {
        for(int i_annee = 2012; i_annee<annee; i_annee++)
        {
            nbreJours+=nbreJoursAnnee(i_annee);
        }
        nbreJours += nbreJoursMoisAnnee(mois, annee);
    }
    else
    {
        for(int i_annee = annee; i_annee<2012; i_annee++)
        {
            nbreJours+=nbreJoursAnnee(i_annee);
        }
        nbreJours -= nbreJoursMoisAnnee(mois, annee);
    }

    return nbreJours;
}

// Rang du premier jour du mois dans la semaine
int funcPremierMois(int mois, int annee)
{
    int rang;
    if(annee>=2012)
        rang = nbreJoursMoisAnnee2012(mois, annee) % 7;
    else
        rang = (7 - nbreJoursMoisAnnee2012(mois,annee)%7)%7;

    return rang;
}

bool inMonth(int indexCase, int mois, int annee)
{
    int premierMois = funcPremierMois(mois, annee);
    int finMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (nbreJoursAnnee(annee)==366)
        finMois[1] = 29;
    int endMonth = finMois[mois];
    if (indexCase>=premierMois && indexCase<premierMois+endMonth)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    for (int i=0;i<42;i++)
    	std::cout << inMonth(i, 1, 2012) << '\n';
    return 0;
}
