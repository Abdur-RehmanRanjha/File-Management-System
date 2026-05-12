#include "txt.h"

txt::txt(string n, node* ptr, string ft) :currentLine(0), file(n, ptr, ft) {}

void txt::create() {
	ofstream newFile(getPath());
	newFile.close();
}

int txt::choice() {
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

void txt::display(int& count) {
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

void txt::loadIntoFile() {
	ofstream currentFile(getPath());
	for (string i : lines) {
		currentFile << i;
		currentFile << endl;
	}
	currentFile.close();
}

void txt::open() {
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

bool txt::Delete() {
	filesystem::remove(getPath());
	return true;
}

txt::~txt() {
	lines.clear();
}