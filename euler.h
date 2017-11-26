#ifndef EULER_H
#define EULER_H

#include <QMainWindow>

namespace Ui {
class Euler;
}

class Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Euler(QWidget *parent = 0);
    ~Euler();
    // Variables decalration
     double limi,lims,h;// These variables will save the lower and higher limits, and the increment provided by the user.
     int i,j,inter;// Auxiliar variables for cycles (i and j). The last variable will save the calculated intervals number.
     double x(double a);// This function will return the differential equation.
     double y(double b);// This function will return the integrated equation.

private:
    Ui::Euler *ui;

public slots:
    void metodo();//statement of methods to be followed
    void borrar();

};

#endif // EULER_H
