#pragma once
#include<iostream>
#include<vector>
#include"file.h"
#include"node.h"
using namespace std;
class zip : public file {
    string sourceNodeName;
    string sourceExtension;
public:
    zip(string, node*, string, string srcNodeName = "", string srcExt = "");
    string getSourceNodeName();
    string getSourceExtension();
    void create(); 
    void open();
    bool Delete();
};