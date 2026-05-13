#include "node.h"

node::node(string n, node* address, string t) :name(n), parent(address), type(t) {}

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
	if (getParent() == nullptr) {
		return name;
	}
	else {
		return parent->getPath() + "/" + name;
	}
}

void node::setName(string n) {
	name = n;
}

vector<node*>& node::getsubnodes() {
	static vector<node*> empty;
	return empty;
}

node::~node() {
	
}