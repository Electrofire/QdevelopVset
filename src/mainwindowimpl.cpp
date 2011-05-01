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
   connect(actionOpen_Workspace, SIGNAL(triggered()), this, SLOT(openWorkspace()));
    
    
   connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

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
        doWait();
        vswork.setTree(treeWidget, true);
        vswork.add_experiment(pathToXML.toStdString());
        doWait();
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
    case Wait:
        cursor = Qt::WaitCursor;
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

void MainWindowImpl::doWait(){
    //Slicing calls here
    setCurrentPointer(Wait);
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
}

void MainWindowImpl::openModel(QTreeWidgetItem *item) {

  Model* model = vswork.getModel(item);
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
 * Cesar Chacon
 * Creates a new workspace .vset file
 * checks if it exits already
 * if it exists asks the user if
 * he/she wants to rewrite the file.
 *
 */
void MainWindowImpl::newWorkspace(){
bool writefile = false;
    //create the streams
ifstream inp;
ofstream out;
string newfilepath;


    QString Path = QFileDialog::getSaveFileName(this, "New file"  ,
     "/", tr("VSeT (*.vst)"));
            
   newfilepath = Path.toStdString() + ".vst";

//try to open the file
inp.open(newfilepath.c_str(), ifstream::in);
//close the file
inp.close();

//if the file exists
if(!inp.fail()){
	//if the file exists then ask the user if he/she wants
	//to overwrite the file
	
QString msg = "The workspace already exists, do you want to overwrite it?";
 QMessageBox msgBox;
 msgBox.setText(msg);
 msgBox.setIcon(QMessageBox::Warning);
 msgBox.setInformativeText("Workspace Already Exists");
 msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
 msgBox.setDefaultButton(QMessageBox::No);
 int ret = msgBox.exec();
 
 if(ret ==QMessageBox::YesRole){
 	writefile=true;
}
 else{
        writefile = false;
}
//cout << "Error...file """ << newfilepath.c_str() << """ exists" << endl;
} else{
	//if the file doesn't exist
	inp.clear(ios::failbit);
	writefile=true;
}
	
	if(writefile){
			
		out.open(newfilepath.c_str(), ofstream::out);
		//print projectname
		//out << vswork.getName() << endl;
		//print all paths to experiments open
		vector<Experiment*> exlist = vswork.getList_of_experiments();
		
		for(unsigned int i=0;i<exlist.size();i++){
	    out<<exlist[i]->getfullPath().c_str()<<endl;
			
		}
		
		//print word visualizations
		//print all visualizations information
	out.close();
	}
}

/*
 * Cesar Chacon
 * unloads the existing workspace.
 * Asks to save the current workspace
 */
void MainWindowImpl::openWorkspace(){
	char buffer[256];
	string temp;
	//The system closes the currently loaded workspace (ALT 1).
	vswork.clearExperimentManager();
	
	//The system opens a file selection dialog displaying 
	//the files in the current working directory.
	   QString pathToWS;
       pathToWS = QFileDialog::getOpenFileName(
        this,
        "Select a workspace to open",
        "/",
        tr("VSeT (*.vst)")
        );


//The user uses the file selection dialog to select the desired workspace (ALT 2) (ALT 3).
if (pathToWS.isNull() == false){
	  ifstream wsfile (pathToWS.toStdString().c_str());
	  
	   while (! wsfile.eof() )
  {
    wsfile.getline (buffer,100);
    temp = buffer;
    if(temp.length()>1){
    vswork.add_experiment(buffer);	
   	}
    
  }
}

//The system opens the workspace description file, displays the model visualization windows
//in the state described in the workspace description file, and loads the model navigation
//window with the names of models available for each of the experiments in the workspace.

	
}
 

