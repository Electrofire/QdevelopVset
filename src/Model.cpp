/* 
 * File:   Model.cpp
 * Author: ahlatimer
 * 
 * Created on March 4, 2011, 7:50 PM
 * Model:
 *   -Superclass to VelocityModel, PerturbationModel, CoverageModel, and TimeModel
 */

#include "Model.h"
//Constructor method
//Takes the path of the binary file, obtains the substring of the path to obtain
// iteration and step
//Sets the object's path and experiment values to the values passed
Model::Model(string path, Experiment *experiment) {   
    this->path = path;
    this->experiment = experiment;
    int slash_pos = path.rfind("/");
    string base_name = path.substr(slash_pos + 1, path.length());
    name = base_name.substr(0, base_name.find(".") - 2);
    iteration = atoi(base_name.substr(base_name.find(".") - 2, 1).c_str());
    step = atoi(base_name.substr(base_name.find(".") - 1, 1).c_str());
    pchild = new QTreeWidgetItem();
    pchildA = new QTreeWidgetItem();
}

Model::Model() {
}

Model::~Model() {
}

int Model::needsDeleteAt(vector<string> files){

    for(int i=0; i< files.size(); i++)
        if(path.compare(files[i]) == 0)
            return i;

    return -1;
}

