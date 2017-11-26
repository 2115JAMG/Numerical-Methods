#ifndef ELIMINACIONGAUSSIANA_H
#define ELIMINACIONGAUSSIANA_H

#include <QMainWindow>

namespace Ui {
class EliminacionGaussiana;
}

class EliminacionGaussiana : public QMainWindow
{
    Q_OBJECT

public:
    explicit EliminacionGaussiana(QWidget *parent = 0);
    ~EliminacionGaussiana();

private:
    Ui::EliminacionGaussiana *ui;

public slots:
    void metodo(); //Slot that performs the gaussian elimination method
    void borrar(); //Slot that erases the contents of the spinbox and text
};

#endif // MAINWINDOW_H
