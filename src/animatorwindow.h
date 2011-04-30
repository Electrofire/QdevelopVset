
#ifndef ANIMATORWINDOW_H
#define ANIMATORWINDOW_H

#include <QDockWidget>
#include <QMainWindow>
#include "ui_animatorwindow.h"
#include "Workspace.h"

    class AnimatorWindow : public QMainWindow, public Ui::AnimatorWindow
{
    Q_OBJECT

public:
    explicit AnimatorWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~AnimatorWindow();
    void setTree();

    Workspace* vwork;

private:
};

#endif // ANIMATORWINDOW_H
