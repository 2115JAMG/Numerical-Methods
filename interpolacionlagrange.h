#ifndef INTERPOLACIONLAGRANGE_H
#define INTERPOLACIONLAGRANGE_H

#include <QMainWindow>

namespace Ui {
class InterpolacionLagrange;
}

class InterpolacionLagrange : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterpolacionLagrange(QWidget *parent = 0);
    ~InterpolacionLagrange();
     double x[5][2];//creation of the increasing arrangement

private:
    Ui::InterpolacionLagrange *ui;
public slots:
    void metodo();//statement of methods to be followed
    void borrar();

};

#endif // INTERPOLACIONLAGRANGE_H
