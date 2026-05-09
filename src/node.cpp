#include "node.h"
#include<iostream>
using namespace std;

node::node(string n, node* address, string t) :name(n), parent(address),type(t) {}

string node::getName() {
	return name;
}

string node::getType() {
	return type;
}