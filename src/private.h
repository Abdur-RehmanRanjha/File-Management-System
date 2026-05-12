#pragma once
#include<iostream>
#include<vector>
#include"file.h"
#include"node.h"
using namespace std;

class Private :public file {
	vector<string> lines;
	int currentLine;
	string passKey;
public:
	Private(string, node*, string);
	bool verification();
	int choice();
	void display(int&);
	void create();
	void open();
	void loadIntoFile();
	bool Delete();
	~Private();
};