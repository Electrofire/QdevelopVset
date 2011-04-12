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
	//cout <<"initial path="<<	path<<endl;
    int slash_pos = path.rfind("/");
    string base_name = path.substr(slash_pos + 1, path.length());
   //DEBUG  cout <<	base_name<<endl;
    name = base_name.substr(0, base_name.find(".") - 2);
   //DEBUG cout<<name<<endl;
    iteration = atoi(base_name.substr(base_name.find(".") - 2, 1).c_str());
  //  cout <<"iteration="<<	iteration<<endl;
   
    step = atoi(base_name.substr(base_name.find(".") - 1, 1).c_str());
    //cout <<"step="<<step<<endl;
   
    this->path = path;
    this->experiment = experiment;
    
}

Model::Model() {
}

Model::~Model() {
}

    int Model::getStep(){
    	return step;
   	}
    int Model::getIteration()
    {
     return iteration;	
   	}
    string Model::getName(){
    	return name;
   	}
   	
void Model::render() {
  cout << "Rendering!";
}

