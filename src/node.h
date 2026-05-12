#pragma once
#include<iostream>
#include<filesystem>
#include<cstdint>
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
	virtual string getPath();
	void setName(string);
	virtual uintmax_t getSize() = 0;
	virtual void create() = 0;
	virtual void open() = 0;
	virtual bool Delete() = 0;
	virtual ~node();
};