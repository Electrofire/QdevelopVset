#ifndef SYNCGROUPWINDOW_H
#define SYNCGROUPWINDOW_H

#include <QMainWindow>
#include "ui_syncgroupwindow.h"

class SyncGroupWindow : public QMainWindow, public Ui::SyncGroupWindow
{
    Q_OBJECT

public:
    explicit SyncGroupWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~SyncGroupWindow();

private:
};

#endif // SYNCGROUPWINDOW_H
