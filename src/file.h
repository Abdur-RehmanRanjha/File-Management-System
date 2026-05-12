#pragma once
#include<iostream>
#include "node.h"
using namespace std;

class file :public node {
	string fileType;
public:
	file(string, node*, string);
	string getFileType();
	uintmax_t getSize();
	virtual string getPath();
	virtual void create() = 0;
	virtual void open() = 0;
	virtual bool Delete() = 0;
	virtual ~file();
};