#include "modelwindow.h"

ModelWindow::ModelWindow(QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
}

void ModelWindow::test(vtkSmartPointer<vtkRenderWindow> renW){
    titis->SetRenderWindow(renW);
}

ModelWindow::~ModelWindow()
{
    delete this;
}
