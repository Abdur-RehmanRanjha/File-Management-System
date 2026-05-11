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
	void ls();
	void mkdir(string);
	void touch(string, string);
	bool exists(string);
	void cd(string);
	node* search(string, vector<node*>);
	folder* getRoot(folder*);
	void rm(string);
	void rename(string);
};