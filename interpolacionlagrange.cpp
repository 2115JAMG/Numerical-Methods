#include "interpolacionlagrange.h"
#include "ui_interpolacionlagrange.h"
#include <Qstring>
#include <cmath>
#include <qmath.h>
#include <qmessagebox.h>


InterpolacionLagrange::InterpolacionLagrange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterpolacionLagrange)
{
    ui->setupUi(this);
    // Connections
connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

InterpolacionLagrange::~InterpolacionLagrange()
{
    delete ui;
}
void InterpolacionLagrange::metodo(){

    QString temp,temp2,temp3,temp4;//text
     x[0][0]=ui->doubleSpinBox->value();
     x[0][1]=ui->doubleSpinBox_2->value();
     x[1][0]=ui->doubleSpinBox_3->value();
     x[1][1]=ui->doubleSpinBox_4->value();
     x[2][0]=ui->doubleSpinBox_5->value();
     x[2][1]=ui->doubleSpinBox_6->value();
     x[3][0]=ui->doubleSpinBox_7->value();
     x[3][1]=ui->doubleSpinBox_8->value();
     double X=ui->doubleSpinBox_9->value();
     int a=5,i,j,k;//variables
     double p,f;


    if(x[0][0]==0){
        QMessageBox msgBox;
        msgBox.setText("Usted ingreso pocos valores para realizar el método.");//suggests entering more than 1 value in X0 to start the method
        msgBox.exec();
        }

        double lagrange[a];//a vector of the size of n
        for(k=1;k<a;k++){//initial the first cycle for the order of the polynomial
            p=0;
            for(i=0;i<k+1;i++){//the cycle is created for the calculation of the formula of the method
                f=1;
                for(j=0;j<k+1;j++){
                    if(i!=j){
                     f=f*((X-x[j][0])/(x[i][0]-x[j][0]));//method of Lagrange in cycles
                    }
                }
                f=f*x[i][1];// multiply the result of the formula by the value of F (x)
                p=p+f;//the value of the polynomial is added
            }
            lagrange[k]=p;//the polynomial is stored in the lagrange vector
        }

//show the text in the interface
    temp.append("Resultado de primer grado: ").append(temp2.setNum(lagrange[1])).append("\n\nResultado de segundo grado: ").append(temp3.setNum(lagrange[2])).append("\n\nResultado de tercer grado: ").append(temp4.setNum(lagrange[3]));
    ui->textEdit->setText(temp);
}
void InterpolacionLagrange::borrar(){ //method borrar
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(0.0);
    ui->doubleSpinBox_4->setValue(0.0);
    ui->doubleSpinBox_5->setValue(0.0);
    ui->doubleSpinBox_6->setValue(0.0);
    ui->doubleSpinBox_7->setValue(0.0);
    ui->doubleSpinBox_8->setValue(0.0);
    ui->doubleSpinBox_9->setValue(0.0);
    ui->textEdit->clear();//the method and window are cleared
}

