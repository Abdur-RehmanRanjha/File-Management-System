#include "file.h"

file::file(string n, node* ptr, string ft) :node(n, ptr, "file") {
	fileType = ft;
}

string file::getPath() {
	if (getParent() == nullptr) {
		return name + "." + fileType;
	}
	else {
		return parent->getPath() + "/" + name + "." + fileType;
	}
}

uintmax_t file::getSize() {
	return filesystem::file_size(this->getPath());
}

string file::getFileType() {
	return fileType;
}

file::~file() {

}