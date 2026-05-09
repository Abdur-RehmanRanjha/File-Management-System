#include "folder.h"
using namespace std;

folder::folder(string n,node* ptr=nullptr) :node(n, ptr, "folder") {
	folderName = n;
}

vector<node*>& folder::getsubnodes() {
	return subNodes;
}
