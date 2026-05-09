#include "node.h"
#include "folder.h"
#include<iostream>
using namespace std;

folder::folder(string n):node(n,nullptr,"folder") {
	folderName = n;
}

vector<node*> folder::getsubnodes() {
	return subNodes;
}
