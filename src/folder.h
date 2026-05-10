#pragma once
#include "node.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class folder :public node {
	vector<node*> subNodes;
public:
	folder(string, string, node*);
	vector<node*>& getsubnodes();
	void create();
	void open();
	void Delete();
};