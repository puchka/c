#include<QPushButton>
#include<QString>
#include<string.h>
#include<stdio.h>
#include"b_case.h"
#include"case.h"

Case::Case(QWidget *parent)
    : QTableWidget(6, 7, parent)
{
    setFixedSize(187, 153);// taille de la table
    resizeColumnsToContents();
    resizeRowsToContents();

    verticalHeader() -> hide(); // On n'affiche pas l'entete verticale
    horizontalHeader() -> setResizeMode(QHeaderView::Fixed);
    horizontalHeader() -> setClickable(false);
    horizontalHeader() -> setStyleSheet("background-color:#8397dc; border:none; ");

    for(int i = 1; i<=3; i++)
    {
        std::string str(" "); // Initialisation à " " sinon erreur
        char * chaine = (char*)str.c_str();   // conversion d'un string en un char* (à la facon C :P)
        sprintf(chaine, "%d", i);

        QString text(chaine);
        b_case[i-1] = new BCase(text, this);
    }

    // placement des cases
    setCellWidget(0, 0, b_case[0]);
    setCellWidget(2, 3, b_case[1]);
    setCellWidget(4, 2, b_case[2]);

    // Connexion des boutons avec les signaux
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if(i!=j)
            {
                QObject::connect(b_case[i], SIGNAL(pressed()),
                             b_case[j], SLOT(resetMoi()));
                QObject::connect(b_case[i], SIGNAL(b_focused()),
                                 b_case[j], SLOT(resetMoi()));
            }
        }
        QObject::connect(b_case[i], SIGNAL(pressed()),b_case[i], SLOT(coloreMoi()));
        QObject::connect(b_case[i], SIGNAL(b_focused()),b_case[i], SLOT(coloreMoi()));
    }

    //On n'affiche pas les grilles
    setShowGrid(false);

    // On Modifie les étiquette de l'entete
    QStringList labels;
    labels << "L" << "M" << "M" << "J" << "V" << "S" << "D" ;
    setHorizontalHeaderLabels(labels);

}
