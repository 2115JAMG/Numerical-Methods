#include "nummethods.h"
#include "ui_nummethods.h"

NumMethods::NumMethods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NumMethods)
{
    ui->setupUi(this);
    Newton=new NR();
    PuntoFijo=new PuntOFijo();
    ElimiGaussiana=new EliminacionGaussiana();
    InterpolaciondeLagrange=new InterpolacionLagrange();
    GuassSeidel=new GaussSeidel();
    Eule=new Euler();
    Diferenciacion= new DifNum();
    Regresion=new Rregresion_Lineal();
    RegresionM=new RregresionLinealMultiple();
    MIntegracion=new Integracion();
    RungeK= new RungeKutta();
//the programs are mentioned agian but now we add "new"

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pt()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(nr()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(eg()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(gs()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(il()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(rl()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(rlm()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(dn()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(i()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(e()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(rk()));

    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(salir()));
//conections with the pogram buttons, wich each button has assigned a program

}

NumMethods::~NumMethods()
{
    delete ui;
}
void NumMethods::pt(){
    PuntoFijo->show();
}

void NumMethods::nr(){
    Newton->show();
}
void NumMethods::eg(){
    ElimiGaussiana->show();
}

void NumMethods::il(){
    InterpolaciondeLagrange->show();
}
void NumMethods::rl(){
    Regresion->show();
}

void NumMethods::rlm(){
    RegresionM->show();
}
void NumMethods::dn(){
    Diferenciacion->show();
}
void NumMethods::gs(){
    GuassSeidel->show();
}
void NumMethods::i(){
    MIntegracion->show();
}

void NumMethods::e(){
    Eule->show();
}

void NumMethods::rk(){
    RungeK->show();
}

//shows the selected program when you click the button
void NumMethods::salir(){
    delete PuntoFijo;
    delete Newton;
    delete ElimiGaussiana;
    delete InterpolaciondeLagrange;
    delete Regresion;
    delete RegresionM;
    delete Diferenciacion;
    delete MIntegracion;
    delete Eule;
    delete RungeK;
    close();
//clean all the program and windows
}
