/**
 * Cesar Chacon
 */
#ifndef __EXPERIMENTMANAGER_H__
#define __EXPERIMENTMANAGER_H__

#include "Experiment.h"
#include "Model.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <iostream>
/**
 * Experiment Manager handles the number of Experiments running
 * and adds or removes certain experiments from the list.
 * Should be used to pupulate the experiment manager widget on the
 * GUI.
 */

class ExperimentManager{
	
public:
	/*Methods*/
    ExperimentManager();
    virtual~ExperimentManager();
    void add(string expStr);
    void remove(string expStr);
    void print_list_of_experiments();
    vector<Experiment*> getList_of_experiments() const;
    void remove_experiment(int index);
    void setTreeWidget(QTreeWidget *TreeWidget, bool main);
    int searchExperiment(string name);
    void initializeExperimentTree(Experiment* new_experiment);
    void updateExperimentTree(Experiment* experiment);
    string convertInt(int number);

    //Manage experiments
    void add_experiment(Experiment*);
    void remove_experiment(Experiment*);
    
    /* Attributes*/
    vector<Experiment*> list_of_experiments_;
    QTreeWidget* treeWidget;
    QTreeWidget* treeWidgetA;
	    
private:
    

};


#endif // __EXPERIMENTMANAGER_H__
