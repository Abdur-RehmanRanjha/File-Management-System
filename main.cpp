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
    root->create();
    commandManager cm(root);
    cout << "---------------------File Management System--------------------" << endl;
    while (menu(cm)!= 0) {}
    cout << "Closing......" << endl;
    root->Delete();
    delete root;
	return 0;
}