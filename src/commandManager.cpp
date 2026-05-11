#include "commandManager.h"

commandManager::commandManager(folder* c) :current(c) {}

void commandManager::ls() {
	for (node* i : (current->getsubnodes())) {
		cout << i->getName() << "\t" << i->getType() << endl;
	}
}

void commandManager::mkdir(string n) {
	string path = current->getPath() + "/" + n;
	filesystem::create_directory(path);
	node* n1 = new folder(n, current);
	current->getsubnodes().push_back(n1);
}

void commandManager::touch(string t, string n) {
	string path;
	if (t == "txt") {
		path = current->getPath() + "" + n + ".txt";
		ofstream newFile(path);
		node* n1 = new txt(n, current, "txt");
		current->getsubnodes().push_back(n1);
		newFile.close();
	}
	else if (t == "private") {
		path = current->getPath() + "" + n + ".priv";
		ofstream newFile(path);
		node* n1 = new Private(n, current, "private");
		current->getsubnodes().push_back(n1);
		newFile.close();
	}
	else if (t == "zip") {
		path = current->getPath() + "" + n + ".zip";
		ofstream newFile(path);
		node* n1 = new zip(n, current, "zip");
		current->getsubnodes().push_back(n1);
		newFile.close();
	}
	else if (t == "audio") {
		path = current->getPath() + "" + n + ".mpg";
		ofstream newFile(path);
		node* n1 = new audio(n, current, "audio");
		current->getsubnodes().push_back(n1);
		newFile.close();
	}
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
	if (n == "..") {
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
	if (target!=nullptr && n!= "root") {
		path = target->getPath();
		if (target->getType() == "folder") {
			filesystem::remove_all(path);
			delete target;
		}
		else {
			node* parent = target->getParent();
			vector<node*>& v = parent->getsubnodes();
			filesystem::remove(path);
			for (auto i = v.begin(); i != v.end(); i++) {
				if (*i == target) {
					v.erase(i);
					break;
				}
			}
			delete target;
		}
	}
	else
		cout << "Node not Found!" << endl;
}

void commandManager::rename(string n) {
	folder* root = getRoot(current);
	if (search(n, root->getsubnodes()) == nullptr) {
		string oldPath = current->getPath();
		current->setName(n);
		filesystem::rename(oldPath, current->getPath());
	}
	else {
		cout << "A node with same name already exists!" << endl;
	}
}
