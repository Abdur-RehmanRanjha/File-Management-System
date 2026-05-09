#pragma once
#include<iostream>
#include "node.h"
using namespace std;

class file :public node {
	string fileName;
	string fileType;
public:
	file(string, node*, string);
	void create();
	void open();
	void Delete();
};