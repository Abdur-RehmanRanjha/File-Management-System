#pragma once
#include "node.h"
#include<string>
class folder :public node {
	string name;
	node* subNodes;
public:{
	folder(string n = "");
	void create();
	void read();
	void update();
	void Delete();
}
};