#include <QApplication>
#include <QPushButton>
#include "case.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QWidget  fenetre;
    fenetre.setFixedSize(300, 250);
    Case * m_case;
    m_case = new Case(&fenetre);
    m_case -> move(50, 50);

    fenetre.show();

    return app.exec();
}
