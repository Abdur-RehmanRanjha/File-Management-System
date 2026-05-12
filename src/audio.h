#pragma once
#include<iostream>
#include<vector>
#include"file.h"
#include"node.h"
using namespace std;

class audio :public file {
public:
	audio(string, node*, string);
	void create();
	void open();
	bool Delete();
};