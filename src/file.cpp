#include "file.h"

file::file(string n, string fp, node* ptr, string ft) :node(n, fp, ptr, "file") {
	fileType = ft;
}