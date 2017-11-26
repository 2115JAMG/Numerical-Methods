#ifndef NUMMETHODS_H
#define NUMMETHODS_H

#include <QMainWindow>
#include "nr.h"
#include "puntofijo.h"
#include "eliminaciongaussiana.h"
#include "interpolacionlagrange.h"
#include "gaussseidel.h"
#include "euler.h"
#include "difnum.h"
#include "rregresionlinealmultiple.h"
#include "rregresion_lineal.h"
#include "integracion.h"
#include "rungekutta.h"
//the project is invleded as if it were part of a library

namespace Ui {
class NumMethods;
}

class NumMethods : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumMethods(QWidget *parent = 0);
    ~NumMethods();
    NR * Newton;
    PuntOFijo * PuntoFijo;
    EliminacionGaussiana*ElimiGaussiana;
    InterpolacionLagrange*InterpolaciondeLagrange;
    GaussSeidel*GuassSeidel;
    Euler*Eule;
    DifNum*Diferenciacion;
    RregresionLinealMultiple*RegresionM;
    Rregresion_Lineal*Regresion;
    Integracion*MIntegracion;
    RungeKutta*RungeK;
//the project is added as well as its new mention in the integrator project
private:
    Ui::NumMethods *ui;
public slots:
    void nr();
    void pt();
    void eg();
    void il();
    void gs();
    void e();
    void dn();
    void rlm();
    void rl();
    void i();
    void rk();
    void salir();
};
//news variables of the programs
#endif // NUMMETHODS_H
