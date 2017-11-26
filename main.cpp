#include "nummethods.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumMethods w;
    w.show();

    return a.exec();
}
