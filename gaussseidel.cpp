#include "gaussseidel.h"
#include "ui_gaussseidel.h"
#include <QString>  //Library for use of text strings
#include <cmath>    //Library for use of mathematical functions

GaussSeidel::GaussSeidel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GaussSeidel)
{
    ui->setupUi(this);
    // Connections
   connect(ui->procesar,SIGNAL(clicked()),this,SLOT(metodo()));
   connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
   connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

GaussSeidel::~GaussSeidel()
{
    delete ui;
}
void GaussSeidel::metodo(){

    QString temp,temp2,temp3,temp4,temp5,temp6,temp7;          //Temporary use text strings
    //The following lines of code retrieve the value of the spinbox for each of the functions.
    double ecc=ui->E00_2->value();   // Retrieves the X1 value of the spinbox
    double e01=ui->E01_2->value();   // X2
    double e02=ui->E02_2->value();   // X3
    double e03=ui->E03_2->value();   // X4

    double e10=ui->E10_2->value();   //Retrieves the X1 value of the spinbox
    double e11=ui->E11_2->value();   // X2
    double e12=ui->E12_2->value();   // X3
    double e13=ui->E13_2->value();   // X4

    double e20=ui->E20_2->value();   //Retrieves the X1 value of the spinbox
    double e21=ui->E21_2->value();   // X2
    double e22=ui->E22_2->value();   // X3
    double e23=ui->E23_2->value();   // X4

    double e30=ui->E30_2->value();   // Retrieves the X1 value of the spinbox
    double e31=ui->E31_2->value();   // X2
    double e32=ui->E32_2->value();   // X3
    double e33=ui->E33_2->value();   // X4

    double r0=ui->R1_2->value();     //Retrieves the A value of the spinbox
    double r1=ui->R2_2->value();     //Retrieves the B value of the spinbox
    double r2=ui->R3_2->value();    //Retrieves the C value of the spinbox
    double r3=ui->R4_2->value();    //Retrieves the D value of the spinbox

    double x=ui->x->value();
    double err=ui->err->value();

    double a=0;
    double e=100;
    double subs,subs1;
    double g0=0,g1=0,g2=0,g3=0;
/*
if (ecc<e10){
    f10=ecc,f12=e01,f13=e02,f14=e03;
    ecc=e10,e01=e11,e02=e12,e03=e13;
    f10=e10,f12=e11,f13=e12,f14=e13;
    }
if (ecc<e20){
    f20=ecc,f21=e01,f22=e02,f23=e03;
    ecc=e20,e01=e21,e02=e22,e03=e23;
    f20=e20,f21=e21,f22=e22,f23=e23;
    }
if (ecc<e30){        //Sorting of the matrix with larger coefficients, which I leave in commentary because it will not be visualized
    f30=ecc,f31=e01,f32=e02,f33=e03;
    ecc=e30,e01=e31,e02=e32,e03=e33;
    f30=e30,f31=e31,f32=e32,f33=e33;
    }
   if(e11<e21){
     f40=e10,f41=e11,f42=e12,f43=e13;
     e21=e11;e22=e12,e23=e13,e20=e10;
     f40=e21,f41=e22,f42=e23,f43=e20;
   }
   if(e11<e31){
      f50=e10,f51=e11,f52=e12,f53=e13;
      e30=e10,e31=e11,e32=e12,e33=e13;
      f50=e30,f51=e31;f52=e32,f53=e33;
   }
*/
//Sorting of the matrix with larger coefficients, which I leave in commentary because it will not be visualized
while(a<x){
 subs1=g0*g1*g2*g3;
 g0=(r0-(e01*g1)-(e02*g2)-(e03*g3))/ecc;
 g1=(r1-(e10*g0)-(e12*g2)-(e13*g3))/e11;
 g2=(r2-(e20*g0)-(e21*g1)-(e23*g3))/e22;
 g3=(r3-(g0*e30)-(g1*e31)-(g2*e32))/e33;
 subs=g0*g1*g2*g3;
 a=a+1;
 e=100*std::abs((subs-subs1)/subs);
}
    temp.append("x1=").append(temp2.setNum(g0)).append("\nx2=").append(temp3.setNum(g1)).append("\nx3=").append(temp4.setNum(g2)).append("\nx4=").append(temp5.setNum(g3)).append("\nIteraciones=").append(temp6.setNum(a)).append("\nError=").append(temp5.setNum(e));  //show the text
    ui->Texto->setText(temp);  //The text is presented
}

void GaussSeidel::borrar(){
    ui->E00_2->setValue(0.00);  //The spinbox is deleted
    ui->E01_2->setValue(0.00);
    ui->E02_2->setValue(0.00);
    ui->E03_2->setValue(0.00);  //The spinbox is deleted
    ui->E10_2->setValue(0.00);
    ui->E11_2->setValue(0.00);
    ui->E12_2->setValue(0.00);  //The spinbox is deleted
    ui->E13_2->setValue(0.00);
    ui->E20_2->setValue(0.00);
    ui->E21_2->setValue(0.00);  //The spinbox is deleted
    ui->E22_2->setValue(0.00);
    ui->E23_2->setValue(0.00);
    ui->E30_2->setValue(0.00);
    ui->E31_2->setValue(0.00);
    ui->E32_2->setValue(0.00);  //The spinbox is deleted
    ui->E33_2->setValue(0.00);
    ui->R1_2->setValue(0.00);
    ui->R2_2->setValue(0.00);
    ui->R3_2->setValue(0.00);
    ui->R4_2->setValue(0.00);
    ui->x->setValue(0.00);
    ui->err->setValue(0.00);
     ui->Texto->clear();   //Text is deleted

}
