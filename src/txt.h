#pragma once
#include<iostream>
#include"file.h"
#include"node.h"
using namespace std;

class txt :public file {
public:
	txt(string, node*, string);
	void create();
	void open();
	void Delete();
};