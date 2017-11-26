#include "euler.h"
#include "ui_euler.h"
#include <Qstring>
#include <cmath>
#include <qmath.h>

Euler::Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Euler)
{
    ui->setupUi(this);//connections within the program
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

double Euler::x(double a){// Function that saves the differential equation.
    return((-2*(a*a*a))+(12*(a*a))-(20*(a))+8.5);// Returns the valued equation.
}
double Euler::y(double b){// Function that saves the integrated equation.
    return(-(0.5*(b*b*b*b))+(4*(b*b*b))-(10*(b*b))+(8.5*b)+1);// Returns the valued equation.
}

Euler::~Euler()
{
    delete ui;
}

void Euler::metodo(){
    QString temp,temp2,temp3,temp4,temp5;
    lims=ui->ls->value();//global variables that will be evalueated by the program
    limi=ui->li->value();
    h=ui->h->value();
    double w;
    w=(lims-limi)/h;//number of interaction
    inter=w;
    double pX[inter];// Creates a temporal array for x points.
    double Yi[inter];// Creates a temporal array for yi results.
    double real[inter];// Creates a temporal array for real y values.
    pX[0]=limi,pX[inter]=lims;// The first "x points" aray position takes the value from lower limit, and the last array position takes the value from higher limit.
    Yi[0]=y(limi), real[0]=y(limi);// The first "yi" array position takes the value from integrated function valued with lower limit.


for(i=1;i<=inter;i++){// This cycle calculates each x point, "yi" and real y.
        pX[i]=pX[i-1]+h;// Calculates each interval (x point), and saves it on a different array position.
        Yi[i]=(Yi[i-1])+(x(pX[i-1]))*h;// Calculates each "yi" value, and saves it on a different array position.
        real[i]=y(pX[i]);// Calculates each real y value, and saves it on a different array position.



temp.append("\nYi calculada: ").append(temp2.setNum(Yi[i])).append("\nYi real: ").append(temp3.setNum(real[i])).append("\n\nIntervalo: ").append(temp4.setNum(i)).append("\n\n");
ui->textEdit->setText(temp);// Shows each "yi" value first and Shows each real y value second
}
}

void Euler::borrar(){//clean the interface of the program
    ui->li->setValue(0.0);
    ui->ls->setValue(0.0);
    ui->h->setValue(0.0);
    ui->textEdit->clear();


}
