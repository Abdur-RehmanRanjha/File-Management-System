#include<iostream>
#include "commandManager.h"
using namespace std;

commandManager::commandManager(folder* c) :current(c) {}

void commandManager::ls() {
	for (node* i : (current->getsubnodes())) {
		cout << i->getName() << "\t" << i->getType() << endl;
	}
}

void commandManager::mkdir() {

}