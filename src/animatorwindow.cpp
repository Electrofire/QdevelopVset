#include "animatorwindow.h"

AnimatorWindow::AnimatorWindow( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
    modelWidget->setColumnCount(3);
    QStringList header;//EP Header
    header << "" << "Name" << "Iteration" << "Step";
    modelWidget->setHeaderLabels(header);//assign headers
    connect(modelWidget, SIGNAL(itemClicked ( QTreeWidgetItem*, int ) ), this, SLOT(showModel(QTreeWidgetItem*)));

    //Updates thread
    updatesT = new updateThread;
    updatesT->start();
}

AnimatorWindow::~AnimatorWindow()
{
    delete this;
}

void AnimatorWindow::setTree(){

    updatesT->vswork = vwork;
    vwork->setTree(modelWidget, false);
}

void AnimatorWindow::showModel(QTreeWidgetItem *item){

    if(item->childCount())
        return;
    Model* model = vwork->getModel(item);
    modelVisualization->render_model(model, modelWindow);
}

void AnimatorWindow::createCheckBoxes(){

    vector<Experiment*> experiments = vwork->getList_of_experiments();
    vector<Model*> models;
    Model* model;
    Experiment* experiment;
    for(int i=0; i<experiments.size(); i++){
        experiment = experiments[i];
        models = experiment->getModels();
        for(int j=0; j<models.size(); j++){
            model = models[i];
            model->pchildA->setCheckState(0, Qt::Checked);

        }
    }
}


