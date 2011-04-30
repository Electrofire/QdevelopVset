/**
* Cesar Chacon
*/
#include "ExperimentManager.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QTreeWidget>
#include <algorithm>

ExperimentManager::ExperimentManager(){

}

//Add experiment to the list
void ExperimentManager::add(string expStr) {

     vector<Model*> models;
     Experiment* new_experiment = new Experiment(expStr);
     models = new_experiment->getModels();
     list_of_experiments_.push_back(new_experiment);
     initializeExperimentTree(new_experiment);
     updateExperimentTree(new_experiment);
}

//Print list of experiments for debugging purposes
void ExperimentManager::print_list_of_experiments()
{
	for(int i = 0; i < list_of_experiments_.size(); i++)
	{
		cout << "Experiment at index [" << i << "]: " << (*list_of_experiments_[i]).getprojectName() << endl;
	}
}

//Remove an experiment from the workspace
//The pointer to the experiment to be removed must be specified
void ExperimentManager::remove_experiment(Experiment* to_be_removed)
{
	//get index of experiment
	int index = -1;
	for(int i = 0; i < list_of_experiments_.size(); i++)
	{
		if(list_of_experiments_[i] == to_be_removed)
		{
			index = i;
			break;
		}
	}
	list_of_experiments_.erase(list_of_experiments_.begin() + index);
}
//Remove an experiment from the workspace
//The index of the experiment to be removed must be specified
void ExperimentManager::remove_experiment(int index)
{
  list_of_experiments_.erase(list_of_experiments_.begin() + index);
}


//Return the list of experiments added to the workspace
vector<Experiment*> ExperimentManager::getList_of_experiments() const
{
  return list_of_experiments_;
}

int ExperimentManager::searchExperiment(string name){

    for(int i=0; i< list_of_experiments_.size(); i++){
        if(list_of_experiments_[i]->getprojectName().compare(name)==0)
            return i;
    }
    return -1; //error?
}

//destructor
ExperimentManager::~ExperimentManager() {

}

//Set the Treewidget reference
void ExperimentManager::setTreeWidget(QTreeWidget *TreeWidget, bool main){
    if(main)
        treeWidget = TreeWidget;
    else
        treeWidgetA = TreeWidget;

}

void ExperimentManager::initializeExperimentTree(Experiment* new_experiment){

    QTreeWidgetItem *root;
    QTreeWidgetItem *rootA;
    QTreeWidgetItem *covItem;
    QTreeWidgetItem *covItemA;
    QTreeWidgetItem *timeItem;
    QTreeWidgetItem *timeItemA;
    QTreeWidgetItem *duItem;
    QTreeWidgetItem *duItemA;
    QTreeWidgetItem *s1Item;
    QTreeWidgetItem *s1ItemA;
    QTreeWidgetItem *s2Item;
    QTreeWidgetItem *s2ItemA;


    //create the root node
    root = new QTreeWidgetItem(treeWidget);
    rootA = new QTreeWidgetItem(treeWidgetA);
    QString projectName = QString::fromStdString(new_experiment->getprojectName());
    root->setText(0, projectName);
    rootA->setText(0, "1"+projectName);

    //subfolder items
    covItem = new QTreeWidgetItem(root);
    covItemA = new QTreeWidgetItem(rootA);
    covItem->setText(0, QObject::tr("Ray Coverage"));
    covItemA->setText(0, QObject::tr("Ray Coverage"));

    timeItem = new QTreeWidgetItem(root);
    timeItemA = new QTreeWidgetItem(rootA);
    timeItem->setText(0, QObject::tr("Time"));
    timeItemA->setText(0, QObject::tr("Time"));

    // QTreeWidgetItem *finalItem = new QTreeWidgetItem(root);
    // finalItem->setText(0, QObject::tr("Velocity"));

    duItem = new QTreeWidgetItem(root);
    duItemA = new QTreeWidgetItem(rootA);
    duItem->setText(0, QObject::tr("Vel Perturbation"));
    duItemA->setText(0, QObject::tr("Vel Perturbation"));

    s1Item = new QTreeWidgetItem(root);
    s1ItemA = new QTreeWidgetItem(rootA);
    s1Item->setText(0, QObject::tr("Smoother 1"));
    s1ItemA->setText(0, QObject::tr("Smoother 1"));

    s2Item = new QTreeWidgetItem(root);
    s2ItemA = new QTreeWidgetItem(rootA);
    s2Item->setText(0, QObject::tr("Smoother 2"));
    s2ItemA->setText(0, QObject::tr("Smoother 2"));

    new_experiment->root = root;
    new_experiment->rootA = rootA;
    new_experiment->covItem = covItem;
    new_experiment->covItemA = covItemA;
    new_experiment->timeItem = timeItem;
    new_experiment->timeItemA = timeItemA;
    new_experiment->duItem = duItem;
    new_experiment->duItemA = duItemA;
    new_experiment->s1Item = s1Item;
    new_experiment->s1ItemA = s1ItemA;
    new_experiment->s2Item = s2Item;
    new_experiment->s2ItemA = s2ItemA;
}

void ExperimentManager::updateExperimentTree(Experiment* experiment){

    vector<Model*> models = experiment->getModels();

    unsigned int i;
    const char * name;
    QTreeWidgetItem *pItem, *pchild, *pItemA, *pchildA;
    QString iter, stp, projectName = QString::fromStdString(experiment->getprojectName());

    //loop to add all the models in the list
    //and add all the nodes to the subfolders

    for(i=0;i<models.size();i++){

        if(models[i]->getName()=="icov"){

            name="Coverage";
            pItem = experiment->covItem;
            pItemA = experiment->covItemA;
        }

        else if(models[i]->getName()=="time"){

            name="Time";
            pItem = experiment->timeItem;
            pItemA = experiment->timeItemA;
        }

        else if(models[i]->getName()=="dusum"){

            name="Vel Perturbation";
            pItem = experiment->duItem;
            pItemA = experiment->duItemA;
        }

        else if(models[i]->getName()=="velaa"){

            name="Smoother 1";
            pItem = experiment->s1Item;
            pItemA = experiment->s1ItemA;
        }

        else if(models[i]->getName()=="dvaa"){

            name="Smoother 2";
            pItem = experiment->s2Item;
            pItemA = experiment->s2ItemA;
        }

        else
            continue;

        pchild = models[i]->pchild;
        pchildA = models[i]->pchildA;

        if(pchild->text(0) == 0){
            pchild = new QTreeWidgetItem(pItem);
            pchildA = new QTreeWidgetItem(pItemA);
        }

        pchild->setText(0, QObject::tr(name));
        pchildA->setText(0, QObject::tr(name));
        pchild->setWhatsThis(0, projectName + " " + QString::fromStdString(models[i]->getPath()));
        pchildA->setWhatsThis(0, projectName + " " + QString::fromStdString(models[i]->getPath()));
        iter = QString::fromStdString(convertInt(models[i]->getIteration()));
        pchild->setText(1, iter);
        pchildA->setText(1, iter);
        stp = QString::fromStdString(convertInt(models[i]->getStep()));
        pchild->setText(2, stp);
        pchildA->setText(2, stp);

        models[i]->pchild = pchild;
        models[i]->pchildA = pchildA;
    }

    treeWidget->setSortingEnabled(true);
    treeWidgetA->setSortingEnabled(true);
    treeWidget->resizeColumnToContents(1);
    treeWidgetA->resizeColumnToContents(1);
    treeWidget->resizeColumnToContents(2);
    treeWidgetA->resizeColumnToContents(2);
    treeWidget->resizeColumnToContents(3);
    treeWidgetA->resizeColumnToContents(3);
    treeWidget->sortItems(1, Qt::AscendingOrder);
    treeWidgetA->sortItems(1, Qt::AscendingOrder);
    treeWidget->sortItems(2, Qt::AscendingOrder);
    treeWidgetA->sortItems(2, Qt::AscendingOrder);
    treeWidget->sortItems(3, Qt::AscendingOrder);
    treeWidgetA->sortItems(3, Qt::AscendingOrder);


}

string ExperimentManager::convertInt(int number){

    if (number == 0)
        return "0";

    string temp="";
    string returnvalue="";

    while (number>0){
        temp+=number%10+48;
        number/=10;
    }

    for (unsigned int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];

    return returnvalue;
}
