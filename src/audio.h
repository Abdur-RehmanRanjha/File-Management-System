#pragma once
#include<iostream>
#include"file.h"
#include"node.h"
using namespace std;

class audio :public file {
public:
	audio(string, string, node*, string);
	void create();
	void open();
	void Delete();
};