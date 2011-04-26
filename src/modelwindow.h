#ifndef MODELWINDOW_H
#define MODELWINDOW_H

#include <QMainWindow>
#include "ui_modelwindow.h"
#include <vtkSmartPointer.h>
#include "vtkRenderWindow.h"

class ModelWindow : public QMainWindow, public Ui::ModelWindow
{
    Q_OBJECT

public:
    explicit ModelWindow(QWidget *parent = 0, Qt::WFlags f = 0 );
    ~ModelWindow();
    void test(vtkSmartPointer<vtkRenderWindow> renW);

private:
};

#endif // MODELWINDOW_H
