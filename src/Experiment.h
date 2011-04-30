/* 
 * File:   Experiment.h
 * Author: ahlatimer
 *
 * Created on March 4, 2011, 8:07 PM
 */

#ifndef EXPERIMENT_H
#define	EXPERIMENT_H

#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <map>
#include "pugixml.hpp"
#include <stdlib.h>
#include "ShotPoint.h"
#include <string>
#include <sys/types.h>
#include <vector>
#include "Model.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>

using namespace std;

class Model;
class Experiment {
    friend class Model;
public:
    /* METHODS */
    Experiment(string filename);
    virtual ~Experiment();
    bool close_model(Model model);
    bool open_model(Model model);
    string getprojectName();
    string getfullPath();
    vector<Model*> getModels();
    int searchModel(string path);
    void parse_paths();
    /* END METHODS*/
    
    /* ATTRIBUTES */

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

    /* END ATTRIBUTES */
private:
    /* METHODS */
    void read_xml();
    void create_models(vector<string> files, int model_type);
    void set_shot_points(pugi::xml_node node);
    
    string coverage_path();
    string time_path();
    string velocity_path();
    string perturbation_path();
    string smoother1_path();
    string smoother2_path();
    string finalfiles_path();

    int getdir(string path, vector<string> &files);
    /* METHODS END */

    /* ATTRIBUTES */
    vector<Model> open_models;
    vector<Model*> models;

    string project_name;
    string project_path;
    string xml_filename;
    int iterations;
    /* TODO: Make this an actual date object. */
    string date;
    int nx;
    int ny;
    int nz;
    float h;
    vector<ShotPoint> shot_points;

    /* ATTRIBUTES END */
};



#endif	/* EXPERIMENT_H */

