#pragma once
#include "node.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class folder :public node {
	string folderName;
	vector<node*> subNodes;
public:
	folder(string, node*);
	vector<node*>& getsubnodes();
	void create();
	void open();
	void Delete();
};