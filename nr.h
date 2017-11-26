#ifndef NR_H
#define NR_H

#include <QMainWindow>

namespace Ui {
class NR;
}

class NR : public QMainWindow
{
    Q_OBJECT

public:
    explicit NR(QWidget *parent = 0);
    ~NR();
    double funcion(double x);

private:
    Ui::NR *ui;

public slots:
    void metodo();
    void borrar();
};

#endif // MAINWINDOW_H
