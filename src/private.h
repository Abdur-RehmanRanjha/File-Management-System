#pragma once
#include<iostream>
#include"file.h"
#include"node.h"
using namespace std;

class Private :public file {
public:
	Private(string, string, node*, string);
	void create();
	void open();
	void Delete();
};