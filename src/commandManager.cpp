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
	current->getsubnodes().push_back(new folder(n, path, current));
}

void commandManager::touch(string t, string n) {
	string path;
	if (t == "txt") {
		path = current->getPath() + "" + n + ".txt";
		ofstream newFile(path);
		current->getsubnodes().push_back(new txt(n, path, current, "txt"));
		newFile.close();
	}
	else if (t == "private") {
		path = current->getPath() + "" + n + ".priv";
		ofstream newFile(path);
		current->getsubnodes().push_back(new Private(n, path, current, "private"));
		newFile.close();
	}
	else if (t == "zip") {
		path = current->getPath() + "" + n + ".zip";
		ofstream newFile(path);
		current->getsubnodes().push_back(new zip(n, path, current, "zip"));
		newFile.close();
	}
	else if (t == "audio") {
		path = current->getPath() + "" + n + ".mpg";
		ofstream newFile(path);
		current->getsubnodes().push_back(new audio(n, path, current, "mpg"));
		newFile.close();
	}
}

void commandManager::search(string n) {
	bool found = false;
	string path;
	for (node* i : current->getsubnodes()) {
		if (i->getType() == "folder") {
			if (i->getName() == n) {
				found = true;
			}
			else {

			}
		}
		else if (i->getType() == "file") {
			if (i->getName() == n) {
				found = true;
				while (i->getParent() != nullptr) {

				}
			}
		}
	}
}