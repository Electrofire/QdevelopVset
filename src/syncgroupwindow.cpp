#include "syncgroupwindow.h"

SyncGroupWindow::SyncGroupWindow( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
}

SyncGroupWindow::~SyncGroupWindow()
{
    delete this;
}
