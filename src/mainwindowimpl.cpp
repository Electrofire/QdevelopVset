/**
 * Cesar Chacon
 * Carlos Gonzalez
 * David Archer
 * Alexandra Ogrey
 */

#include <QFileDialog>
#include <QtGui>
#include <QString>
#include <QMessageBox>
#include "mainwindowimpl.h"
#include <sstream>


void loadXMLFromStart(string l, Workspace *vswork);
//
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
    
   connect(actionNew_Workspace, SIGNAL(triggered()), this, SLOT(newWorkspace()));
    
    
   connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    //connect vel
    connect(treeWidget, SIGNAL(itemDoubleClicked ( QTreeWidgetItem*, int ) ), this, SLOT(openModel(QTreeWidgetItem*, int)));

    //vswork connect widgets to references
    vswork.setTree(treeWidget);

    //Initialize custom cursor pointers
    QBitmap zoomB("zoom.png");
    QBitmap rotateB("rotate.png");
    QBitmap sliceB("slice.png");
    QBitmap hourglass("hourglass.png");
    zoomCursor = QCursor(zoomB, -1, -1);
    rotateCursor = QCursor(rotateB, -1, -1);
    sliceCursor = QCursor(sliceB, -1, -1);
    hourglassCursor = QCursor(hourglass, -1, -1);
    //Get any arguments passed from the command line
  QStringList args =  QCoreApplication::arguments();
	
	if(args.size()>1){
	  //get the second argument because the first one is the name of
	  //the application itself
	  QString path = args.at(1);
	  if (path.length()>1){//do only if we have an argument than 1
	  	loadXMLFromStart(path.toStdString(), &vswork);
	 	}
  	}
 }
//

//Opens the file dialog and
//gets a string to the XML file
void MainWindowImpl::openSelect()
{
        //Open Select XML Dialog and filter the files
        //by extension
        QString pathToXML;
       pathToXML = QFileDialog::getOpenFileName(
        this,
        "Select XML to load Experiment",
        "/",
        tr("XML (*.xml);; All files (*.*)")
        );

        //add experiment to the vector of experiments in the manager
 if ( pathToXML.isNull() == false )
    {
    	setHourglassCursor();
        vswork.add_experiment(pathToXML.toStdString());
		setDefaultCursor();
    }
       
    
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

/**
 * Function that sets the cursor to a
 * default wait cursor.
 */
void MainWindowImpl::setHourglassCursor(){
			setCursor(Qt::WaitCursor);  
}
/**
 * Function that sets the cursor to the
 * default arrow cursor.
 */
void MainWindowImpl::setDefaultCursor(){
	  setCursor(Qt::ArrowCursor);
}

void MainWindowImpl::OpenAnimatorWindow(){

    AnimatorWindow * win = new AnimatorWindow();
    win->show();
    win->activateWindow();
}



void MainWindowImpl::openModel(QTreeWidgetItem *item, int index) {

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


/**
 * Gets executed if and only if
 * an arguments has been received from the
 * command line.
 */

void loadXMLFromStart(string pathXMLfromarg, Workspace *vswork){

QString path = QString::fromStdString(pathXMLfromarg);
 QMessageBox msgBox;
 msgBox.setText(path);
 msgBox.setInformativeText("informative text");
 msgBox.setStandardButtons(QMessageBox::Cancel);
 msgBox.setDefaultButton(QMessageBox::Cancel);
 int ret = msgBox.exec();
   
   vswork->add_experiment(pathXMLfromarg);
	
}

/**
 * Cesar
 * Creates a new workspace
 */
void MainWindowImpl::newWorkspace(){
/**
    
ifstream inp;
ofstream out;
string newfilepath;

    QString Path = QFileDialog::getSaveFileName(this, "New file"  ,
     "/",
            tr("VSeT (*.vst)"));
            
             
	newfilepath = Path.toStdString() + ".vst";

//try to open the file
inp.open(newfilepath, ifstream::in);
//close the file
inp.close();

//if we could not open the file
//then the file doesn't exist and
//we can write to a file
if(inp.fail())
{
inp.clear(ios::failbit);
out.open(newfilepath, ofstream::out);
//print projectname
out << vswork.getName() << endl;
//print all paths to experiments open
vector<Experiment*> exlist = vswork.getList_of_experiments();

for(unsigned int i=0;i<exlist.size();i++){
	exlist.
	
}

//print word visualizations
//print all visualizations information
out.close();
}
else
{
cout << "Error...file """ << myFileName.c_str() << """ exists" << endl;
} 
 */
 
}