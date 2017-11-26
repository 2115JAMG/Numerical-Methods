#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <QMainWindow>

namespace Ui {
class GaussSeidel;
}

class GaussSeidel : public QMainWindow
{
    Q_OBJECT

public:
    explicit GaussSeidel(QWidget *parent = 0);
    ~GaussSeidel();

private:
    Ui::GaussSeidel *ui;
public slots:
    void metodo(); //Slot that performs the gaussian elimination method
    void borrar(); //Slot that erases the contents of the spinbox and text
};

#endif // GAUSSSEIDEL_H
