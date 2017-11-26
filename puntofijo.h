#ifndef PUNTOFIJO_H
#define PUNTOFIJO_H

#include <QMainWindow>

namespace Ui {
class PuntOFijo;
}

class PuntOFijo : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuntOFijo(QWidget *parent = 0);
    ~PuntOFijo();
    double funcion(double c);

private:
    Ui::PuntOFijo *ui;

public slots:
    void metodo();
    void borrar();
};

#endif // MAINWINDOW_H
