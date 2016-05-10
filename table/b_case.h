#ifndef B_CASE_H
#define B_CASE_H

#include<QPushButton>
#include<QTableWidget>
#include<string>
#include<QWidget>

class BCase: public QPushButton
{
    Q_OBJECT

public:
    BCase(const QString text, QWidget *parent);

public slots:
    void coloreMoi();   // colore la case si cliquée ou en focus
    void resetMoi();    // reinitialise les autres case si une autre est cliqué

signals:
    void b_focused();    // signal emis quand une case est en focus

private:

};

#endif // B_CASE_H
