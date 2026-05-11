#include "file.h"

file::file(string n, node* ptr, string ft) :node(n, ptr, "file") {
	fileType = ft;
}

file::~file() {

}