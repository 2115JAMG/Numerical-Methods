#include "difnum.h"
#include "ui_difnum.h"
#include <Qstring>
#include <cmath>
#include <qmath.h>
#include <qmessagebox.h>

DifNum::DifNum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DifNum)
{
    ui->setupUi(this);
    // Connections
connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));
connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

DifNum::~DifNum()
{
    delete ui;
}
double DifNum::funcion1(double v)//original ecuation
{
    return
 ((-0.1*pow(v,4))-(0.15*pow(v,3))-(0.5*pow(v,2))-((0.25*v)+1.2));
}
double  DifNum::funcion2(double v)
{//first derivate
    return (-(0.4*pow(v,3))-(0.45*pow(v,2))-(v)-(0.25));
}
double  DifNum::funcion3(double v)
{//second derivate
    return (-(1.2*pow(v,2))-(0.9*v)-(1));
}
double  DifNum::funcion4(double v)
{//third derivate
    return (-(2.4*v)-(0.9));
}
double  DifNum::funcion5(double v)
{//fourth derivate
    return (-2.4);
}
void DifNum::metodo(){

    QString temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11,temp12,temp13,temp14,temp15,temp16,temp17,temp18,temp19,temp20,temp21,temp22,temp23,temp24,temp25;//text
    double xm5=ui->X1_2->value();
    double fm5=ui->F1_2->value();
    double xm4=ui->X1->value();
    double fm4=ui->F1->value();
    double xm3=ui->X2->value();
    double fm3=ui->F2->value();
    double xm2=ui->X3->value();
    double fm2=ui->F3->value();
    double xm1=ui->X4->value();
    double fm1=ui->F4->value();
    double xi=ui->X5->value();
    double fi=ui->F5->value();
    double x1=ui->X6->value();
    double f1=ui->F6->value();
    double x2=ui->X7->value();
    double f2=ui->F7->value();
    double x3=ui->X8->value();
    double f3=ui->F8->value();
    double x4=ui->X9->value();
    double f4=ui->F9->value();
    double f5=ui->F10->value();
    double x5=ui->X10->value();
    double h=ui->h->value();
    double Fm1,Fm2,Fm3,Fm4,F1,F2,F3,F4,Fa1,Fa2,Fa3,Fa4,Em1,Em2,Em3,Em4,E1,E2,E3,E4,Ea1,Ea2,Ea3,Ea4;


    if(h==0){
        QMessageBox msgBox;
        msgBox.setText("Usted no ingreso H la cual es fundamental para que el método funcione (si no el método queda indeterminado).");//suggests entering more than 1 value in X0 to start the method
        msgBox.exec();
        }

        //first derivative
    //Forward method
    Fa1=((-f2)+(4*(f1))-(3*(fi)))/(2*h);
    Ea1=100*std::abs((funcion2(xi)-(Fa1))/(funcion2(xi)));
    //central method
    F1=((-f2)+(8*(f1))-(8*(fm1))+(fm2))/(12*h);
    E1=100*std::abs((funcion2(xi)-(F1))/(funcion2(xi)));
    //backward method
    Fm1=((3*(fi))-(4*(fm1))+(fm2))/(2*h);
    Em1=100*std::abs((funcion2(xi)-(Fm1))/(funcion2(xi)));


        //second derivative
    //Forward method
    Fa2=((-f3)+(4*(f2))-(5*(f1))+(2*(fi)))/(pow(h,2));
    Ea2=100*std::abs(((funcion3(xi))-(Fa2))/(funcion3(xi)));
    //central method
    F2=((-f2)+(16*(f1))-(30*(fi))+(16*(fm1))-(fm2))/(12*pow(h,2));
    E2=100*std::abs(((funcion3(xi))-(F2))/(funcion3(xi)));
    //backward method
    Fm2=((2*(fi))-(5*(fm1))+(4*(fm2))-(fm3))/(pow(h,2));
    Em2=100*std::abs(((funcion3(xi))-(Fm2))/(funcion3(xi)));


        //third derivative
    //Forward method
    Fa3=((-3*(f3))+(14*(f3))-(24*(f2))+(18*(f1))-(5*(fi)))/(2*pow(h,3));
    Ea3=100*std::abs(((funcion4(xi))-(Fa3))/(funcion4(xi)));
    //central method
    F3=((-f3)+(8*(f2))-(13*(f1))+(13*(fm1))-(8*(fm2))+(fm3))/(8*pow(h,3));
    E3=100*std::abs(((funcion4(xi))-(F3))/(funcion4(xi)));
    //backward method
    Fm3=((5*(fi))-(18*(fm1))+(24*(fm2))-(14*(fm3))+(3*(fm4)))/(2*pow(h,3));
    Em3=100*std::abs(((funcion4(xi))-(Fm3))/(funcion4(xi)));


        //fourth derivative
    //Forward method
    Fa4=((-2*(f5))+(11*(f4))-(24*(f3))+(26*(f2))-(14*(f1))+(3*(fi)))/(pow(h,4));
    Ea4=funcion5(xi);
    //central method
    F4=((-f3)+(12*(f2))+(39*(f1))+(56*(fi))-(39*(fm1))+(12*(fm2))+(fm3))/(6*pow(h,4));
    E4=funcion5(xi);
    //backward method
    Fm4=((3*(fi))-(14*(fm1))+(26*(fm2))-(24*(fm3))+(11*(fm4))-(2*(fm5)))/(pow(h,4));
    Em4=funcion5(xi);


//show the text in the interface
    temp
            .append("\nPRIMERA DERIVADA\n")
                .append("\nDerivada trasera\n\n")
                    .append("f(x)'=").append(temp2.setNum(Fm1)).append("\t\nError=").append(temp3.setNum(Em1))
                .append("\n\nDerivada centrada\n\n")
                    .append("f(x)'=").append(temp4.setNum(F1)).append("\t\nError=").append(temp5.setNum(E1))
                .append("\n\nDerivada delantera\n\n")
                    .append("f(x)'=").append(temp6.setNum(Fa1)).append("\t\nError=").append(temp7.setNum(Ea1))

           .append("\n\nSEGUNDA DERIVADA\n\n")
                .append("\nDerivada trasera\n\n")
                    .append("f(x)''=").append(temp8.setNum(Fm2)).append("\t\nError=").append(temp9.setNum(Em2))
                .append("\n\nDerivada centrada\n\n")
                    .append("f(x)''=").append(temp10.setNum(F2)).append("\t\nError=").append(temp11.setNum(E2))
                .append("\n\nDerivada delantera\n\n")
                    .append("f(x)''=").append(temp12.setNum(Fa2)).append("\t\nError=").append(temp13.setNum(Ea2))

            .append("\n\nTERCERA DERIVADA\n\n")
                .append("\nDerivada trasera\n\n")
                    .append("f(x)'''=").append(temp14.setNum(Fm3)).append("\t\nError=").append(temp15.setNum(Em3))
                .append("\n\nDerivada centrada\n\n")
                    .append("f(x)'''=").append(temp16.setNum(F3)).append("\t\nError=").append(temp17.setNum(E3))
                .append("\n\nDerivada delantera\n\n")
                    .append("f(x)'''=").append(temp18.setNum(Fa3)).append("\t\nError=").append(temp19.setNum(Ea3))

            .append("\n\nCUARTA DERIVADA\n\n")
                 .append("\nDerivada trasera\n\n")
                     .append("f(x)''''=").append(temp20.setNum(Fm4)).append("\t\nError=").append(temp21.setNum(Em4))
                 .append("\n\nDerivada centrada\n\n")
                     .append("f(x)''''=").append(temp22.setNum(F4)).append("\t\nError=").append(temp23.setNum(E4))
                 .append("\n\nDerivada delantera\n\n")
                     .append("f(x)''''=").append(temp24.setNum(Fa4)).append("\t\nError=").append(temp25.setNum(Ea4));
    ui->textEdit->setText(temp);
}
void DifNum::borrar(){ //method borrar
    ui->X1_2->setValue(0.0);
    ui->X1->setValue(0.0);
    ui->X2->setValue(0.0);
    ui->X3->setValue(0.0);
    ui->X4->setValue(0.0);
    ui->X5->setValue(0.0);
    ui->X6->setValue(0.0);
    ui->X7->setValue(0.0);
    ui->X8->setValue(0.0);
    ui->X9->setValue(0.0);
    ui->X10->setValue(0.0);
    ui->F1_2->setValue(0.0);
    ui->F1->setValue(0.0);
    ui->F2->setValue(0.0);
    ui->F3->setValue(0.0);
    ui->F4->setValue(0.0);
    ui->F5->setValue(0.0);
    ui->F6->setValue(0.0);
    ui->F7->setValue(0.0);
    ui->F8->setValue(0.0);
    ui->F9->setValue(0.0);
    ui->F10->setValue(0.0);
    ui->h->setValue(0.0);
    ui->textEdit->clear();//the method and window are cleared
}

