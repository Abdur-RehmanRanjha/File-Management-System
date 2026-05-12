#pragma once
#include "node.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class folder :public node {
	vector<node*> subNodes;
public:
	folder(string, node*);
	vector<node*>& getsubnodes() override;
	uintmax_t getSize();
	void create();
	void open();
	bool Delete();
	~folder();
};