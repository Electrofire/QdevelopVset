#include "animatorwindow.h"

AnimatorWindow::AnimatorWindow( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
    modelWidget->setColumnCount(3);
    QStringList header;//EP Header
    header << "Name" << "Iteration" << "Step";
    modelWidget->setHeaderLabels(header);//assign headers
    //vwork->setTree(modelWidget, false);
}

AnimatorWindow::~AnimatorWindow()
{
    delete this;
}

void AnimatorWindow::setTree(){

    vwork->setTree(modelWidget, false);
}


