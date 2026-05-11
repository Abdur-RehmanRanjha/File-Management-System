#pragma once
#include<iostream>
#include<filesystem>
#include<string>
#include<fstream>
using namespace std;
class node {
protected:
	string name;
	node* parent;
	string type;
public:
	node(string, node*, string);
	virtual vector<node*>& getsubnodes();
	string getName();
	string getType();
	node*& getParent();
	string getPath();
	void setName(string);
	/*virtual void create() = 0;
	virtual void open() = 0;
	virtual void Delete() = 0;*/
	virtual ~node();
};