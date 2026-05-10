#pragma once
#include<iostream>
#include "node.h"
using namespace std;

class file :public node {
	string fileType;
public:
	file(string, string, node*, string);
	/*virtual void create() = 0;
	virtual void open() = 0;
	virtual void Delete() = 0;*/
};