#pragma once
#include<iostream>
#include"file.h"
#include"node.h"
using namespace std;

class zip :public file {
public:
	zip(string, node*, string);
	void create();
	void open();
	void Delete();
};