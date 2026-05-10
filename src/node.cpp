#include "node.h"

node::node(string n, string p, node* address, string t) :name(n), path(p), parent(address), type(t) {}

string node::getName() {
	return name;
}

string node::getType() {
	return type;
}

node*& node::getParent() {
	return parent;
}

string node::getPath() {
	return path;
}