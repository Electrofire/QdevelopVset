#include "animatorwindow.h"

AnimatorWindow::AnimatorWindow( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
    modelWidget->setColumnCount(3);
    QStringList header;//EP Header
    header << "Name" << "Iteration" << "Step";
    modelWidget->setHeaderLabels(header);//assign headers
    //vwork->setTree(modelWidget, false);
}

AnimatorWindow::~AnimatorWindow()
{
    delete this;
}

void AnimatorWindow::setTree(){

    vwork->setTree(modelWidget, false);
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
            if(experiment->searchModel(model->getPath()) == -1){
                model->pchildA->setFlags(model->pchildA->flags()|Qt::ItemIsUserCheckable);
                model->pchildA->setCheckState(0, Qt::Checked);
            }
        }
    }
}


