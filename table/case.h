#ifndef CASE_H
#define CASE_H

#include<QWidget>
#include<QLabel>
#include<QTableWidget>
#include<QHeaderView>
#include<QStringList>
#include"b_case.h"

class Case : public QTableWidget     // On hérite de QTableWidget
{
    Q_OBJECT

public:
    Case(QWidget *parent);
    void inscrire_val(int ligne, int colonne, int val);

public slots:

private:
    BCase * b_case[3];
};

#endif // CASE_H
