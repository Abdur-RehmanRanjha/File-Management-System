#pragma once
#include "node.h"
#include<string>
#include<iostream>
class folder :public node {
	node* subNodes;
public:
	folder();
	void create();
	void read();
	void update();
	void Delete();
};