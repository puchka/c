#include <QApplication>
#include "clock.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    QGridLayout layt;

    Clock clk(350);
    //layt.addWidget(&clk,0, 0);
    //fenetre.setLayout(&layt);

    //clk.setParent(&fenetre);


    //fenetre.setWindowFlags(Qt::FramelessWindowHint);
    clk.show();


    return app.exec();
}
