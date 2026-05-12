#include "commandManager.h"

commandManager::commandManager(folder* c) :current(c) {}

void commandManager::ls() {
	for (node* i : (current->getsubnodes())) {
		cout << i->getName() << "\t" << i->getType() << "\t";
		cout << i->getSize() / 1024 << " KB" << endl;
	}
}

void commandManager::mkdir(string n) {
	if (search(n, getRoot(current)->getsubnodes()) == nullptr) {
		node* n1 = new folder(n, current);
		n1->create();
		current->getsubnodes().push_back(n1);
	}
	else
		cout << "A node with same name already exists!" << endl;
}

void commandManager::touch(string t, string n) {
	string path;
	if (search(n, (getRoot(current))->getsubnodes()) == nullptr) {
		if (t == "txt") {
			node* n1 = new txt(n, current, "txt");
			n1->create();
			current->getsubnodes().push_back(n1);
		}
		else if (t == "private") {
			node* n1 = new Private(n, current, "private");
			n1->create();
			current->getsubnodes().push_back(n1);
		}
		else if (t == "zip") {
			path = current->getPath() + "/" + n + ".zip";
			ofstream newFile(path);
			node* n1 = new zip(n, current, "zip");
			current->getsubnodes().push_back(n1);
			newFile.close();
		}
		else if (t == "audio") {
			node* n1 = new audio(n, current, "mpg");
			n1->create();
			current->getsubnodes().push_back(n1);
		}
	}
	else
		cout << "A node with same name already exists!" << endl;
}

folder* commandManager::getRoot(folder* cur) {
	folder* root;
	if (cur->getParent() != nullptr) {
		root = dynamic_cast<folder*>(cur->getParent());
		while (root->getParent() != nullptr) {
			root = dynamic_cast<folder*>(root->getParent());
		}
		return root;
	}
	else
		return cur;
}

node* commandManager::search(string n, vector<node*> v) {
	for (node* i : v) {
		if (i->getName() == n) {
			return i;
		}
		if (i->getType() == "folder") {
			node* found = search(n, i->getsubnodes());
			if (found != nullptr)
				return found;
		}
	}
	return nullptr;
}

bool commandManager::exists(string n) {
	node* found = search(n, current->getsubnodes());
	if (found != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void commandManager::cd(string n) {
	if (n == ".." && current!= getRoot(current)) {
		current = dynamic_cast<folder*> (current->getParent());
		return;
	}
	else {
		if (exists(n)) {
			node* n1 = search(n, current->getsubnodes());
			if (n1->getType()=="folder") {
				current = dynamic_cast<folder*>(n1);
			}
			else
				cout << "Cannot cd into a file!" << endl;
		}
		else {
			cout << "Node Not Found!" << endl;
		}
	}
}

void commandManager::rm(string n) {
	string path;
	node* target = search(n, current->getsubnodes());
	if (target != nullptr && n!= "root") {
		path = target->getPath();
		if (target->getType() == "folder") {
			target->Delete();
			delete target;
		}
		else {
			if (target->Delete()) {
				node* parent = target->getParent();
				vector<node*>& v = parent->getsubnodes();
				for (auto i = v.begin(); i != v.end(); i++) {
					if (*i == target) {
						v.erase(i);
						break;
					}
				}
				delete target;
			}
		}
	}
	else
		cout << "Node not Found!" << endl;
}

void commandManager::rename(string oldName, string newName) {
	folder* root = getRoot(current);
	node* nodeToRename;
	if (search(newName, root->getsubnodes()) == nullptr) {
		nodeToRename = search(oldName, current->getsubnodes());
		if (nodeToRename != nullptr) {
			string oldPath = nodeToRename->getPath();
			nodeToRename->setName(newName);
			filesystem::rename(oldPath, nodeToRename->getPath());
		}
		else {
			cout << "Node Does not exist in this folder" << endl;
		}
	}
	else {
		cout << "A node with same name already exists!" << endl;
	}
}

void commandManager::opened(string n) {
	node* toOpen = search(n, current->getsubnodes());
	if (toOpen != nullptr) {
		toOpen->open();
		cd(n);
	}
	else {
		cout << "Node does not exist in this folder!" << endl;
	}
}