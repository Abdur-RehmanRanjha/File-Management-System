#pragma once
#include<iostream>
#include<filesystem>
#include "folder.h"
using namespace std;

class commandManager {
	folder* current;
public:
	commandManager(folder*);
	void ls();
	void mkdir();
};