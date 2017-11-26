#ifndef DIFNUM_H
#define DIFNUM_H

#include <QMainWindow>

namespace Ui {
class DifNum;
}

class DifNum : public QMainWindow
{
    Q_OBJECT

public:
    explicit DifNum(QWidget *parent = 0);
    ~DifNum();
    double funcion1(double v);//funtions thats we uses for derivations
    double funcion2(double v);//first derivate
    double funcion3(double v);//second derivate
    double funcion4(double v);//third derivate
    double funcion5(double v);//fourth derivate


private:
    Ui::DifNum *ui;

public slots:
    void metodo();//statement of methods to be followed
    void borrar();
};

#endif // DIFNUM_H

