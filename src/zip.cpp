#include "zip.h"

zip::zip(string n, node* ptr, string ft, string srcN, string srcE) :sourceNodeName(srcN), sourceExtension(srcE), file(n, ptr, ft) {}

string zip::getSourceNodeName() { 
    return sourceNodeName;
}
string zip::getSourceExtension() { 
    return sourceExtension; 
}

void zip::create() {}

void zip::open() {
    cout << "Zipped files cannot be opened, unzip first." << endl;
}

bool zip::Delete() {
    filesystem::remove(getPath());
    return true;
}