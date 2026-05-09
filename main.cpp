#include<iostream>
#include<fstream>
using namespace std;

int main() {
	cout << "Hello World";
	fstream read("root/hello.txt");
	fstream* address = &read;
	cout << address;
	return 0;
}