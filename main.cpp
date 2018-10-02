#include "bmicalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BMICalc w;
    w.show();

    return a.exec();
}
