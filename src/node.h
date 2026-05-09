#pragma once
#include<iostream>
using namespace std;
class node {
protected:
	string name;
	node* parent;
	string type;
public:
	node(string, node*, string);
	string getName();
	string getType();
	virtual void create() = 0;
	virtual void open() = 0;
	virtual void Delete() = 0;
};