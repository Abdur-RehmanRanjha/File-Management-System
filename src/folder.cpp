#include "folder.h"
using namespace std;

folder::folder(string n, node* ptr = nullptr) :node(n, ptr, "folder") {}

vector<node*>& folder::getsubnodes() {
	return subNodes;
}

folder::~folder() {
	for (node* i : subNodes) {
		delete i;
	}
	subNodes.clear();
}
