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
		else if (t == "audio") {
			node* n1 = new audio(n, current, "mpg");
			n1->create();
			current->getsubnodes().push_back(n1);
		}
		else {
			cout << "Unknown file type. Use: txt, private, audio" << endl;
			cout << "To zip an existing node use: zip <nodeName>" << endl;
		}
	}
	else
		cout << "A node with same name already exists!" << endl;
}

void commandManager::cd(string n) {
	if (n == "..") {
		if (current->getParent() != nullptr) {
			current = dynamic_cast<folder*> (current->getParent());
		}
		else
			cout << "Already at Root!" << endl;
		return;
	}
	else {
		node* n1 = search(n,current->getsubnodes());
		if (n1 != nullptr) {
			if (n1->getType() == "folder") {
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



void commandManager::rm(string n) {
	string path;
	node* target = search(n, current->getsubnodes());
	if (target != nullptr && n!= "root") {
		path = target->getPath();
		if (target->getType() == "folder") {
			target->Delete();
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
		if (toOpen->getType() == "folder")
			cd(n);
	}
	else {
		cout << "Node does not exist in this folder!" << endl;
	}
}

void commandManager::zipNode(string n) {
	node* target = nullptr;
	for (node* i : current->getsubnodes()) {
		if (i->getName() == n) {
			target = i;
			break;
		}
	}
	if (target == nullptr) {
		cout << "Node \"" << n << "\" not found in the current folder." << endl;
		return;
	}
	if (target->getType() == "file") {
		file* f = dynamic_cast<file*>(target);
		if (f && f->getFileType() == "zip") {
			cout << "Cannot zip a zip file." << endl;
			return;
		}
	}
	string zipNodeName = n + "-zip";
	string zipFilePath = current->getPath() + "/" + zipNodeName + ".zip";
	if (search(zipNodeName, getRoot(current)->getsubnodes()) != nullptr) {
		cout << "A node named \"" << zipNodeName << "\" already exists." << endl;
		return;
	}
	string srcExt;
	if (target->getType() == "folder") {
		srcExt = "folder";
	}
	else {
		file* f = dynamic_cast<file*>(target);
		srcExt = f ? f->getFileType() : "";
	}
	string srcPath = target->getPath();
	string command = "powershell -Command \"Compress-Archive -Path '"
		+ srcPath + "' -DestinationPath '"
		+ zipFilePath + "' -Force\"";
	cout << "Zipping \"" << n << "\"..." << endl;
	int result = system(command.c_str());
	if (result != 0) {
		cout << "Error: Could not create zip file. Make sure PowerShell is available." << endl;
		return;
	}
	zip* zipNode = new zip(zipNodeName, current, "zip", n, srcExt);
	current->getsubnodes().push_back(zipNode);
	cout << "Created: " << zipNodeName << ".zip" << endl;
}

void commandManager::unzip(string n) {
	node* target = nullptr;
	for (node* i : current->getsubnodes()) {
		if (i->getName() == n) {
			target = i;
			break;
		}
	}
	if (target == nullptr) {
		cout << "Node \"" << n << "\" not found in the current folder." << endl;
		return;
	}
	if (target->getType() != "file") {
		cout << "\"" << n << "\" is not a file." << endl;
		return;
	}
	zip* zipFile = dynamic_cast<zip*>(target);
	if (zipFile == nullptr) {
		cout << "\"" << n << "\" is not a zip file." << endl;
		return;
	}
	string unzippedName = n + "-unzipped";
	if (search(unzippedName, getRoot(current)->getsubnodes()) != nullptr) {
		cout << "A node named \"" << unzippedName << "\" already exists." << endl;
		return;
	}
	string srcExt = zipFile->getSourceExtension();
	bool   wasFolder = (srcExt == "folder");
	string destDir = current->getPath() + "/" + unzippedName;
	string command = "powershell -Command \"Expand-Archive -Path '"
		+ zipFile->getPath() + "' -DestinationPath '"
		+ destDir + "' -Force\"";
	cout << "Unzipping \"" << n << "\"..." << endl;
	int result = system(command.c_str());
	if (result != 0) {
		cout << "Error: Could not unzip file. Make sure PowerShell is available." << endl;
		return;
	}
	if (wasFolder) {
		folder* newFolder = new folder(unzippedName, current);
		current->getsubnodes().push_back(newFolder);
		cout << "Unzipped folder: " << unzippedName << endl;
	}
	else {
		string srcNodeName = zipFile->getSourceNodeName();
		string innerFilePath = destDir + "/" + srcNodeName + "." + srcExt;
		string finalPath = current->getPath() + "/" + unzippedName + "." + srcExt;
		string moveCmd = "powershell -Command \"Move-Item -Path '"
			+ innerFilePath + "' -Destination '"
			+ finalPath + "' -Force\"";
		system(moveCmd.c_str());
		string rmCmd = "powershell -Command \"Remove-Item -Path '"
			+ destDir + "' -Recurse -Force\"";
		system(rmCmd.c_str());
		node* newNode = nullptr;
		if (srcExt == "txt") {
			newNode = new txt(unzippedName, current, "txt");
		}
		else if (srcExt == "private") {
			newNode = new Private(unzippedName, current, "private");
		}
		else if (srcExt == "mpg") {
			newNode = new audio(unzippedName, current, "mpg");
		}
		else {
			newNode = new txt(unzippedName, current, srcExt);
		}
		current->getsubnodes().push_back(newNode);
		cout << "Unzipped file: " << unzippedName << "." << srcExt << endl;
	}
}