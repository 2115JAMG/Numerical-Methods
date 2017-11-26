#include "nr.h"
#include "ui_nr.h"
#include "cmath"

NR::NR(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NR)
{
    ui->setupUi(this);
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));

}

NR::~NR()
{
    delete ui;
}
//Enter the function to be evaluated
double NR::funcion(double x){
     return exp(-x)-x;
      //F(x)´= -exp(-x)-1;      //the first derivate of the funtion
}
//read the values entered by the user
void NR::metodo(){
    QString temp,temp2,temp3,temp4;
    double x1=ui->X1->value();
    double err=ui->Err->value();
    double ite=ui->Err_2->value();
    double xr=0.0;
    double ea=100.0;
    double i=0;
    double x2=0;
    double y,c;

                                           //The cycle is created for the solution of the method
    while((ea>err)&&(i<ite)){
xr=(1-(exp(-x1)-x1))/(-exp(-x1)-1);    //evalue the funtion, with the first derivate
ea=100*std::abs((xr-x1)/xr);           //The error is calculated
y= floor(ea);                           //the error is improved
c=(ea-y)*err;                           // the error is correct
x1=xr;                                 //change the value of X1 with the result of Xr
x2=xr;                                 //change the value x2 with xr
i=i+1;                                 //Increases the counter depending on the number of necessary interactions


    }
    //the result is generated as string
    temp.append("Raíz ubicada en: ").append(temp2.setNum(x2)).append("\nError de: %").append(temp3.setNum(c)).append("\nNúmero de iteraciones: ").append(temp4.setNum(i));
    ui->Texto->setText(temp);
}
//funtion "Limpiar" is defined to clean the interface
void NR::borrar(){
    ui->X1->setValue(0.0);
    ui->Err->setValue(0.0);
    ui->Err_2->setValue(0.0);
    ui->Texto->clear();
}


