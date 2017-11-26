#include "eliminaciongaussiana.h"
#include "ui_eliminaciongaussiana.h"
#include <QString>  //Library for use of text strings
#include <cmath>    //Library for use of mathematical functions

EliminacionGaussiana::EliminacionGaussiana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EliminacionGaussiana)
{
    ui->setupUi(this);
    // Connections
connect(ui->procesar,SIGNAL(clicked()),this,SLOT(metodo()));
connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

EliminacionGaussiana::~EliminacionGaussiana()
{
    delete ui;
}

void EliminacionGaussiana::metodo(){

    QString temp,temp2,temp3,temp4,temp5;          //Temporary use text strings
    //The following lines of code retrieve the value of the spinbox for each of the functions.
    double ecc=ui->E00->value();   // Retrieves the X1 value of the spinbox
    double e01=ui->E01->value();   // X2
    double e02=ui->E02->value();   // X3
    double e03=ui->E03->value();   // X4

    double e10=ui->E10->value();   //Retrieves the X1 value of the spinbox
    double e11=ui->E11->value();   // X2
    double e12=ui->E12->value();   // X3
    double e13=ui->E13->value();   // X4

    double e20=ui->E20->value();   //Retrieves the X1 value of the spinbox
    double e21=ui->E21->value();   // X2
    double e22=ui->E22->value();   // X3
    double e23=ui->E23->value();   // X4

    double e30=ui->E30->value();   // Retrieves the X1 value of the spinbox
    double e31=ui->E31->value();   // X2
    double e32=ui->E32->value();   // X3
    double e33=ui->E33->value();   // X4

    double r0=ui->R1->value();     //Retrieves the A value of the spinbox
    double r1=ui->R2->value();     //Retrieves the B value of the spinbox
    double r2=ui->R3->value();    //Retrieves the C value of the spinbox
    double r3=ui->R4->value();    //Retrieves the D value of the spinbox
    double p=ecc;                  // Recovers the value of the equation
    double i=e03;                  //
    double s=e02;                  //
    double o=e01;                  //
    double f10,f12,f13,f14,f20,f21,f22,f23,f24,f30,f31,f32,f33,f34;  // Variables for substituting rows
    double f11=0,g0,g1,g2,g3,d0,d1,d2,d3,a,h0,h1,h2,x4,x3,x2,x1,y1,y2,y3,y4,y5;

do{                                   //Evaluation formula.
        y1=e10-(e10/ecc)*ecc;
        y2=e11-(e10/ecc)*e01;
        y3=e12-(e10/ecc)*e02;
        y4=e13-(e10/ecc)*e03;
        y5=r1-(e10/ecc)*r0;
   if(a==1){                                       //Data storage for second row row
        f10=y1; f11=y2; f12=y3; f13=y4; f14=y5;    //change of values in spinbox
        e10=e20; e11=e21; e12=e22; e13=e23;r1=r2;
   }
   if(a==2){                                    // third row data storage.
        f20=y1; f21=y2; f22=y3; f23=y4; f24=y5;//substitution for the calculation of the next row
        e10=e30; e11=e31; e12=e32; e13=e33; r1=r3;
   }
   if(a==3)                                           //fourth row storage
   {                                                  //substitution of variables
       f30=y1; f31=y2; f32=y3; f33=y4; f34=y5;
       e10=f21; ecc=f11; e11=f22; e12=f23; e13=f24;
       e01=f12; e02=f13; e03=f14;
   }
   if(a==4)
   {
       g0=y1; g1=y2; g2=y3; g3=y4;               //data storage
       e10=f31; ecc=f11; e11=f32; e12=f33; e13=f34;  //substitution of variables
       e01=f12; e02=f13; e03=f14;
   }
   if(a==5)                                    //data storage
   {                                           //substitution of variables
       d0=y1; d1=y2; d2=y3; d3=y4;
       e10=d1; ecc=g1; e11=d2; e12=d3;
       e01=g2; e02=g3;
   }
   if(a==6)                                 // data storage
   {
       h0=y1; h1=y2; h2=y3;
   }
   if(a==7)
   {                                        //variable clearance x4,x3,x2,x1
       x4=h2/h1;
       x3=(g3-(g2*x4))/(g1);
       x2=(f14-(f12*x3)-(f13*x4))/(f11);
       x1=(r0-(x4*i)-(s*x3)-(o*x2))/(p);
   }
        a++;
    }
while(a<8);

    temp.append("x1=").append(temp2.setNum(x1)).append("\nx2=").append(temp3.setNum(x2)).append("\nx3=").append(temp4.setNum(x3)).append("\nx4=").append(temp5.setNum(x4));  //Show the text
    ui->Texto->setText(temp);  //The text is presented
}

void EliminacionGaussiana::borrar(){
    ui->E00->setValue(0.0);  //The spinbox is deleted
    ui->E01->setValue(0.0);
    ui->E02->setValue(0.0);
    ui->E03->setValue(0.0);  //The spinbox is deleted
    ui->E10->setValue(0.0);
    ui->E11->setValue(0.0);
    ui->E12->setValue(0.0);  //The spinbox is deleted
    ui->E13->setValue(0.0);
    ui->E20->setValue(0.0);
    ui->E21->setValue(0.0);  //The spinbox is deleted
    ui->E22->setValue(0.0);
    ui->E23->setValue(0.0);
    ui->E30->setValue(0.0);
    ui->E31->setValue(0.0);
    ui->E32->setValue(0.0);  //The spinbox is deleted
    ui->E33->setValue(0.0);
    ui->R1->setValue(0.00);
    ui->R2->setValue(0.00);
    ui->R3->setValue(0.00);
    ui->R4->setValue(0.00);
    ui->Texto->clear();   //Text is deleted

}

