#include "node.h"

node::node(string n, node* address, string t) :name(n), parent(address),type(t) {}

string node::getName() {
	return name;
}

string node::getType() {
	return type;
}

node*& node::getParent() {
	return parent;
}