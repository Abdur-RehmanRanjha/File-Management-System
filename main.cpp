#include<iostream>
#include<fstream>
#include "src/commandManager.h"
#include "src/node.h"
#include "src/folder.h"
#include "src/file.h"
#include "src/menu.h"
using namespace std;

int main() {
    folder* root = new folder("root", nullptr);
    folder* first = new folder("first", root);
    file* n1 = new zip("n1", first, "zip");
    root->create();
    first->create();
    n1->create();
    commandManager cm(root);
    cout << root->getPath() << endl;
    cout << first->getPath() << endl;
    cout << n1->getPath() << endl;
    cout << "[" << cm.getCurrent()->getPath() << "] > " << endl << endl;
    cm.cd("first");
    cout << "[" << cm.getCurrent()->getPath() << "] > " << endl << endl;
    cout << "---------------------File Management System--------------------" << endl;
    while (menu(cm)!= 0) {}
    cout << "Closing......" << endl;
	return 0;
}