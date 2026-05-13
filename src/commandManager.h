#pragma once
#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
#include "file.h"
#include "txt.h"
#include "private.h"
#include "zip.h"
#include "audio.h"
#include "folder.h"
using namespace std;

class commandManager {
	folder* current;
public:
	commandManager(folder*);
	folder* getCurrent() {
		return current;
	}
	void ls();
	void mkdir(string);
	void touch(string, string);
	void cd(string);
	node* search(string, vector<node*>);
	folder* getRoot(folder*);
	void rm(string);
	void rename(string, string);
	void opened(string);
	void zipNode(string);
	void unzip(string);
};