#include "file.h"

file::file(string n, node* ptr, string ft) :node(n, ptr, "file") {
	fileName = n;
	fileType = ft;
}