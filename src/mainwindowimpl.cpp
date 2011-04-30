/**
 * Cesar Chacon
 * Carlos Gonzalez
 * David Archer
 */

#include <QFileDialog>
#include <QtGui>
#include "mainwindowimpl.h"
#include <sstream>

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
    setupUi(this);
    //initialize Experiment Manager
    treeWidget->setColumnCount(3);
    QStringList header;//EP Header
    header << "Name" << "Iteration" << "Step";
    treeWidget->setHeaderLabels(header);//assign headers

    //connect the signal related to the top bars
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openSelect()));
    connect(actionOpen_2, SIGNAL(clicked()), this, SLOT(openSelect()));
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(actionSave_1, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(actionSave_2, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(actionAnimator, SIGNAL(clicked()), this, SLOT(OpenAnimatorWindow()));
    connect(actionZoom_1, SIGNAL(clicked()), this, SLOT(doZoom()));
    connect(actionZoom, SIGNAL(triggered()), this, SLOT(doZoom()));
    connect(actionSlice, SIGNAL(triggered()), this, SLOT(doSlice()));
    connect(actionSlice_1, SIGNAL(clicked()), this, SLOT(doSlice()));
    connect(actionPan, SIGNAL(triggered()), this, SLOT(doPan()));
    connect(actionRotate, SIGNAL(triggered()), this, SLOT(doRotate()));

    //connect vel
    connect(treeWidget, SIGNAL(itemDoubleClicked ( QTreeWidgetItem*, int ) ), this, SLOT(openModel(QTreeWidgetItem*)));

    //Initialize custom cursor pointers
    QBitmap zoomB("zoom.png");
    QBitmap rotateB("rotate.jpeg");
    QBitmap sliceB("slice.png");
    zoomCursor = QCursor(zoomB, -1, -1);
    rotateCursor = QCursor(rotateB, -1, -1);
    sliceCursor = QCursor(sliceB, -1, -1);
    win = new AnimatorWindow();
    win->vwork = &vswork;
    win->setTree();
 }
//

//Opens the file dialog and
//gets a string to the XML file
void MainWindowImpl::openSelect()
{
        //Open Select XML Dialog and filter the files
        //by extension
        QString fileName;
        fileName = QFileDialog::getOpenFileName(
        this,
        "Select XML to load Experiment",
        "/",
        tr("XML (*.xml);; All files (*.*)")
        );

        //add experiment to the vector of experiments in the manager

        vswork.setTree(treeWidget, true);
        vswork.add_experiment(fileName.toStdString());
}

/**
  Store Binary file name
**/
void MainWindowImpl::saveFile(){

    if(!getBINfile()){
        QString fileName = QFileDialog::getSaveFileName(
        this,
        "Save current Experiment",
        "/",
        tr("Binary (*.VSeT)")
        );

        setBINfile(fileName);
    }
}

//Check for key events
void MainWindowImpl::keyPressEvent( QKeyEvent * event ){
    switch ( event->key() ){

        case Qt::Key_Escape:

            setCurrentPointer(-1);
            break;
        default:break;

    }
}

//Stop current action
void MainWindowImpl::stopAction(int action){

    switch(action){
    case Slice:
        break;
    case Zoom:
        break;
    case Pan:
        break;
    case Rotate:
        break;

    }
}

//Change current Cursor POinter according to the current action
void MainWindowImpl::setCurrentPointer(int nextAction){

    QCursor cursor = NULL;
    if(currentAction == nextAction){
        nextAction = -1;
        stopAction(currentAction);
    }
    switch(nextAction){
    case Slice:
        cursor = sliceCursor;
        break;
    case Zoom:
        cursor = zoomCursor;
        break;
    case Pan:
        cursor = Qt::OpenHandCursor;
        break;
    case Rotate:
        cursor = rotateCursor;
        break;
    default:
        cursor = Qt::ArrowCursor;
    }
    setCursor(cursor);
    currentAction = nextAction;
}

void MainWindowImpl::doSlice(){
    //Slicing calls here
    setCurrentPointer(Slice);
}

void MainWindowImpl::doZoom(){
    //Zoom calls here
    setCurrentPointer(Zoom);
}

void MainWindowImpl::doPan(){
    //Pan calls here
    setCurrentPointer(Pan);
}

void MainWindowImpl::doRotate(){
    //Rotate calls here
    setCurrentPointer(Rotate);
}


void MainWindowImpl::OpenAnimatorWindow(){

    if(!win->isVisible()){
        win->show();
        win->activateWindow();
        vswork.updateExperimentsTree();

    }

    else{
        win->hide();
    }
    //}
}

void MainWindowImpl::refreshTreeItems()
{

}


void MainWindowImpl::openModel(QTreeWidgetItem *item) {

  string modelInfo = item->whatsThis(0).toStdString();
  int next = modelInfo.rfind(" ");
  string ExperimentName = modelInfo.substr(0, next);
  string ModelName = modelInfo.substr(next+1, modelInfo.length());

  Model* model = vswork.getModel(ExperimentName, ModelName);
  Visualization* vis = new Visualization();
  vswork.add_visualization(vis);
  vis->render_model(model);

}

std::string MainWindowImpl::intToString(int i)
{
    std::stringstream ss;
    std::string s;
    ss << i;
    s = ss.str();

    return s;
}
