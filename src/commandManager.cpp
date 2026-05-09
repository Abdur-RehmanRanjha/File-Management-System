#include "commandManager.h"

commandManager::commandManager(folder* c) :current(c) {}

void commandManager::ls() {
	for (node* i : (current->getsubnodes())) {
		cout << i->getName() << "\t" << i->getType() << endl;
	}
}

void commandManager::mkdir(string n) {
	current->getsubnodes().push_back(new folder(n, current));
}

void commandManager::touch(string t, string n) {
	
}