#pragma once
#include<iostream>
#include<filesystem>
#include<string>
#include<fstream>
using namespace std;
class node {
protected:
	string name;
	string path;
	node* parent;
	string type;
public:
	node(string, string, node*, string);
	string getName();
	string getType();
	node*& getParent();
	string getPath();
	/*virtual void create() = 0;
	virtual void open() = 0;
	virtual void Delete() = 0;*/
};