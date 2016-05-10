#include"b_case.h"
#include"case.h"

BCase::BCase(const QString text, QWidget * parent)
    : QPushButton(text, parent)
{
    QPushButton::setStyleSheet("border:none");
    if (hasFocus())
    {
        emit b_focused();     // emettre un signal lors d'un focus
    }
}

/*void BCase::afficheMoi(int ligne, int colonne, int val)
{
    QTableWidget::setCellWidget(ligne, colonne, this);
}*/

void BCase::coloreMoi()
{
    setStyleSheet("background-color: #bcd977; border:none");
}

void BCase::resetMoi()
{   
    setStyleSheet("background-color: white; border: none;");
}
