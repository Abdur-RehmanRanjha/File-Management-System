#include "folder.h"
using namespace std;

folder::folder(string n, node* ptr) :node(n, ptr, "folder") {}

vector<node*>& folder::getsubnodes() {
	return subNodes;
}

uintmax_t folder::getSize() {
	uintmax_t size = 0;
	for (node* i : this->getsubnodes()) {
		size += i->getSize();
	}
	return size;
} 

void folder::create() {
	filesystem::create_directory(this->getPath());
}

void folder::open() {
	cout << "Location: " << this->getPath() << endl;
}

bool folder::Delete() {
	filesystem::remove_all(getPath());
	return true;
}

folder::~folder() {
	for (node* i : subNodes) {
		delete i;
	}
	subNodes.clear();
}
