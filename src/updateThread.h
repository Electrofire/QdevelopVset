#ifndef UPDATETHREAD_H
#define UPDATETHREAD_H

#include <QThread>
#include "Workspace.h"

class updateThread : public QThread {

public:

    virtual void run();

    Workspace* vswork;

};

#endif // UPDATETHREAD_H
