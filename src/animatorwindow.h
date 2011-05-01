
#ifndef ANIMATORWINDOW_H
#define ANIMATORWINDOW_H

#include <QDockWidget>
#include <QMainWindow>
#include "ui_animatorwindow.h"
#include "Workspace.h"
#include "updateThread.h"

    class AnimatorWindow : public QMainWindow, public Ui::AnimatorWindow
{
    Q_OBJECT

public:
    explicit AnimatorWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~AnimatorWindow();
    void setTree();
    void createCheckBoxes();

    Workspace* vwork;

private:

    Visualization* modelVisualization;
    updateThread * updatesT;

private slots:

    void showModel(QTreeWidgetItem* item);

};

#endif // ANIMATORWINDOW_H
