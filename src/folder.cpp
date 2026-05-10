#include "folder.h"
using namespace std;

folder::folder(string n, string p, node* ptr = nullptr) :node(n, p, ptr, "folder") {}

vector<node*>& folder::getsubnodes() {
	return subNodes;
}
