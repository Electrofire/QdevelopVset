/*
 * Workspace.cpp
 *
 *      Author: Joel Quintana, Cesar Chacon
 *
 *      WORKSPACE
 *      This class contains all the information relevant to a
 *  Visualization Project
 *      Contains:
 *      - keeps track of added experiments
 *      - keeps track of visualizations opened
 *      - keeps track of synchronization groups
 *      - has the ability to save to and load from disk
 *      - calls the animation interface
 *
 *		Last update: 11:13 am / 25 / March / 2011
 */

#include "Workspace.h"
#include "ExperimentManager.h"

//Default constructor
Workspace::Workspace()
{
	name_ = "Default";
}

//Default destructor
Workspace::~Workspace()
{

}

//Accessr for the name
string Workspace::getName() const
{
    return name_;
}

//Mutator for the name
void Workspace::setName(string name_)
{
    this->name_ = name_;
}

//Return the list of experiments added to the workspace
vector<Experiment*> Workspace::getList_of_experiments() const {
  return expMan.getList_of_experiments();
}

//Return the list of visualizations opened in the workspace
vector<Visualization*> Workspace::getList_of_visualizations() const {
  return list_of_visualizations_;
}

//Add a new experiment to the workspace
//The experiment will be added to the end of the list
void Workspace::add_experiment(string expstring){

    return expMan.add(expstring);
}

//Add a new visualization to the workspace
//The new visualization will be added to the end of the list
void Workspace::add_visualization(Visualization* new_visualization)
{
	list_of_visualizations_.push_back(new_visualization);
}

//Remove a visualization from the workspace
//The index of the visualization must be specified
void Workspace::remove_visualization(int index)
{
	list_of_visualizations_.erase(list_of_visualizations_.begin() + index);
}

//Remove a visualization from the workspace
//The pointer to the visualization to be removed must be specified
void Workspace::remove_visualization(Visualization* to_be_removed)
{
	//get index of experiment
	int index = -1;

	for(int i = 0; i < list_of_visualizations_.size(); i++)
	{
		if(list_of_visualizations_[i] == to_be_removed)
		{
			index = i;
			break;
		}
	}
	list_of_visualizations_.erase(list_of_visualizations_.begin() + index);
}

//Set Tree Widget Reference
void Workspace::setTree(QTreeWidget *TreeWidget, bool main){
        expMan.setTreeWidget(TreeWidget, main);
}

//Search ModelPath in ExperimentName and return a model
Model* Workspace::getModel(string experimentName, string ModelPath){

    int exp = expMan.searchExperiment(experimentName);
    Experiment* experiment = expMan.getList_of_experiments()[exp];
    int modeli = experiment->searchModel(ModelPath);
    return experiment->getModels()[modeli];
}

void Workspace::updateExperimentsTree(){

<<<<<<< HEAD
    vector<Experiment*> experiments = getList_of_experiments();
    for(int i=0; i< experiments.size(); i++){
        experiments[i]->parse_paths();
        expMan.updateExperimentTree(experiments[i]);
    }
}
=======
/**
 *Cesar Chacon
 * Saves the workspace to a text file
 * Format:
 * <<Workspace Name>>
 * <<home/username/project.xml>>
 * <<home/username/project2.xml>>
 * <<home/username/project3.xml>>
 * Visualizations
 * <</home/username/project/icov.3d>>
 * <<X position of the window>>
 * <<Y position of the window>>
 */
void Workspace::save_workspace(string){
	
	
}

void Workspace::clearExperimentManager(){
	expMan.clearTree();
	
}
/**
int main()
{
	cout << "Running" << endl;

	cout << "\nInitializing workspace" << endl;
	Workspace my_workspace;

	cout << "\nCreate some experiments" << endl;
	Experiment e1 = Experiment("e1");
	cout << "Created: " << e1.getprojectName() << endl;

	Experiment e2 = Experiment("e2");
	cout << "Created: " << e2.getprojectName() << endl;

	Experiment e3 = Experiment("e3");
	cout << "Created: " << e3.getprojectName() << endl;

	cout << "\nAdding experiments to the workspace" << endl;
	my_workspace.add_experiment(&e1);
	my_workspace.add_experiment(&e2);
	my_workspace.add_experiment(&e3);
	cout << "Added" << endl;

	cout << "List experiments in the workspace" << endl;
	my_workspace.print_list_of_experiments();

	cout << "\nRemove experiment at index 1" << endl;
	my_workspace.remove_experiment(1);

	cout << "List experiments in the workspace again to show the change" << endl;
	my_workspace.print_list_of_experiments();

	cout << "\nRemove experiment e1" << endl;
	my_workspace.remove_experiment(&e1);

	cout << "List experiments in the workspace again to show the change" << endl;
	my_workspace.print_list_of_experiments();

	cout << "\nComplete" << endl;
}**/
>>>>>>> 236eb128dfd296219f38bd435f15714e346b569d
