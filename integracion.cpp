#include "integracion.h"
#include "ui_integracion.h"
#include <Qstring>
#include <cmath>
#include <qmath.h>
#include <qmessagebox.h>


Integracion::Integracion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Integracion)
{
    ui->setupUi(this);
    // Connections
connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));
connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

Integracion::~Integracion()
{
    delete ui;
}
void Integracion::metodo(){
    QString temp,temp2;//text
     double y1=ui->Y0->value();
     double y2=ui->Y1->value();
     double y3=ui->Y2->value();
     double y4=ui->Y3->value();
     double y5=ui->Y4->value();
     double y6=ui->Y5->value();
     double y7=ui->Y6->value();
     double y8=ui->Y7->value();
     double y9=ui->Y8->value();
     double y10=ui->Y9->value();
     double x0=ui->X1_2->value();
     double x1=ui->X1->value();
     double x2=ui->X2->value();
     double x3=ui->X3->value();
     double x4=ui->X4->value();
     double x5=ui->X5->value();
     double x6=ui->X6->value();
     double x7=ui->X7->value();
     double x8=ui->X8->value();
     double x9=ui->X9->value();
     double h=ui->h->value();
     double r,r1,r2,r3,r4,r5,rt;

     if(h==0){
         QMessageBox msgBox;
         msgBox.setText("Usted no ingreso H la cual es fundamental para que el método se realice (si no el método no funciona).");//suggests entering more than 1 value in X0 to start the method
         msgBox.exec();//shows a waring
         }

r1=y1+(2*y2);//step by step method is performed to avoid data difference errors
r2=(2*y3)+(2*y4);
r3=(2*y5)+(2*y6);
r4=(2*y7)+(2*y8);
r5=(2*y9)+y10;
rt=(h*(r1+r2+r3+r4+r5))/2;//result


//show the text in the interface
        temp.append("Resultado aproximado de la integral es = ").append(temp2.setNum(rt)).append(" U²");
        ui->textEdit->setText(temp);
    }
    void Integracion::borrar(){ //method borrar
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
        ui->Y0->setValue(0.0);
        ui->Y1->setValue(0.0);
        ui->Y2->setValue(0.0);
        ui->Y3->setValue(0.0);
        ui->Y4->setValue(0.0);
        ui->Y5->setValue(0.0);
        ui->Y6->setValue(0.0);
        ui->Y7->setValue(0.0);
        ui->Y8->setValue(0.0);
        ui->Y9->setValue(0.0);
        ui->textEdit->clear();//the method and window are cleared
    }
