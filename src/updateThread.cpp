
#include "updateThread.h"

void updateThread::run(){

    while(true){
        sleep(5);
        vswork->updateExperimentsTree();
    }
}
