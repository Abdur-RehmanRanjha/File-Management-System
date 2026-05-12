#pragma once
#include<iostream>
#include<vector>
#include"file.h"
#include"node.h"
using namespace std;

class txt :public file {
	vector<string> lines;
	int currentLine;
public:
	txt(string, node*, string);
	int choice();
	void display(int&);
	void create();
	void open();
	void loadIntoFile();
	bool Delete();
	~txt();
};