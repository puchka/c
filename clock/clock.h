#ifndef CLOCK_H
#define CLOCK_H
#include <QtGui>

class Clock : public QWidget
{
    Q_OBJECT

    public:
        Clock();
        Clock(int i_size);
    private:
        void paintEvent(QPaintEvent* event);
        int size, halfsize; // width & height
        double scale;//scale of width = scale of height x = y
    public slots:
        void disp();



};

#endif // CLOCK_H
