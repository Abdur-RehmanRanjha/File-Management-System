#include "private.h"

Private::Private(string n, node* ptr, string ft) :currentLine(0),file(n, ptr, ft) {}

void Private::create() {
	string key;
	cout << "Choose the Pass key for this File: ";
	cin.ignore();
	getline(cin, key);
	passKey = key;
	ofstream newFile(getPath());
	newFile.close();
}

int Private::choice() {
	int option;
	cout << endl << endl << "Move the Cursor Up a Line: 1" << endl;
	cout << "Move the Cursor Down a Line: 2" << endl;
	cout << "Add a Line: 3" << endl;
	cout << "Update Line: 4" << endl;
	cout << "Close: 0" << endl;
	cout << "Enter Your Choice: ";
	cin >> option;
	return option;
}

void Private::display(int& count) {
	cout << "Name: " << this->getName() << endl;
	for (auto i = lines.begin();i != lines.end(); i++) {
		if (count == currentLine) {
			cout << "> " << *i;
		}
		else
			cout << *i;
		cout << endl;
		count++;
	}
}

void Private::loadIntoFile() {
	ofstream currentFile(getPath());
	for (string i : lines) {
		currentFile << i;
		currentFile << endl;
	}
	currentFile.close();
}

void Private::open() {
	if (!verification()) { 
		return; 
	}
	int option;
	do {
		int count = 0;
		display(count);
		option = choice();
		if (option == 0) {
			system("cls");
			cout << "Exiting File!" << endl;
			break;
		}
		else if (option == 1 && currentLine >= 1) {
			currentLine--;
		}
		else if (option == 2 && currentLine < count - 1) {
			currentLine++;
		}
		else if (option == 3) {
			string newLine;
			cout << "Enter the New Line: ";
			cin.ignore();
			getline(cin, newLine);
			lines.insert(lines.begin() + currentLine, newLine);
		}
		else if (option == 4) {
			string newLine;
			cin.ignore();
			getline(cin, newLine);
			lines[currentLine] = newLine;
		}
		else {
			cout << "Enter a Valid Choice!" << endl;
			system("cls");
			continue;
		}
		system("cls");
		count = 0;
		display(count);
	} while (option != 0);
	loadIntoFile();
}

bool Private::verification() {
	string key;
	for (int i = 0;i < 3;i++) {
		cout << "Enter Pass Key to get Access: ";
		cin.ignore();
		getline(cin, key);
		if (key != passKey) {
			cout << "Wrong Key!" << endl;
		}
		else {
			return true;
		}
	}
	cout << "3 Failed Attempts Reached! Try Again Later" << endl;
	return false;
}

bool Private::Delete() {
	if (verification()) {
		int choice;
		cout << "Are you Sure?" << endl;
		cout << "1: Yes\n2: No" << endl;
		cin >> choice;
		if (choice == 1) {
			filesystem::remove(getPath());
			return true;
		}
		else if (choice == 2)
			return false;
		else {
			cout << "Invalid Choice!" << endl;
			return false;
		}
	}
	else
		return false;
}

Private::~Private() {
	lines.clear();
}

