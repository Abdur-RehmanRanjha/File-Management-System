#include "menu.h"
#include<cstring>

int inputNum(char s, char e) {
	char num[50];
	int n;
	while (true) {
		cin.getline(num, 50);
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You exceeded the length!\n";
			cout << "Invalid!Enter Again: ";
			continue;
		}
		int size = strlen(num);
		if (size == 0) {
			cout << "It Cannot be Empty!\n";
			cout << "Invalid!Enter Again: ";
			continue;
		}
		bool valid = true;
		int start = 0;
		while (start < size && num[start] == ' ')
			start++;
		int end = size - 1;
		while (end >= 0 && num[end] == ' ')
			end--;
		int digit = 0;
		for (int i = start; i <= end; i++) {
			if (!(num[i] >= s && num[i] <= e)) {
				valid = false;
				break;
			}
			else
				digit++;
		}
		if (digit == 0)
			valid = false;
		if (!valid) {
			cout << "Invalid!Enter Again: ";
			continue;
		}
		else {
			n = stoi(num);
			break;
		}
	}
	return n;
}

int menu(commandManager& cm) {
	cout << "[" << cm.getCurrent()->getPath() << "] > " << endl << endl;
	cout << "1: ls\n2: mkdir\n3: touch\n4: cd\n5: search\n6: rm\n";
	cout << "7: rename\n8: zip\n9: unzip\n0: exit\n";
	cout << "\nEnter Your Choice: ";
	int choice = inputNum('0', '9');
	int secondaryChoice;
	if (choice == 1) {
		cm.ls();
	}
	else if (choice == 2) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		cm.mkdir(name);
		cout << "\n\nWant to get this folder in open state?\t Yes: 1\tNo: 2\t: ";
		secondaryChoice = inputNum('1', '2');
		if (secondaryChoice == 1) {
			cm.opened(name);
		}
	}
	else if (choice == 3) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		cout << "\nChoose Type\n";
		cout << "1: Txt\t2: Private\t3: Audio\n";
		secondaryChoice = inputNum('1', '3');
		if (secondaryChoice == 1) {
			cm.touch(name, "txt");
		}
		else if (secondaryChoice == 2) {
			cm.touch(name, "private");
		}
		else if (secondaryChoice == 3) {
			cm.touch(name, "mpg");
		}
		cout << "\n\nWant to get this file in open state?\t Yes: 1\tNo: 2\t: ";
		secondaryChoice = inputNum('1', '2');
		if (secondaryChoice == 1) {
			cm.opened(name);
		}
	}
	else if (choice == 4) {
		string name;
		cout << "\nEnter Name (.. to go to parent): ";
		getline(cin, name);
		cm.cd(name);
	}
	else if (choice == 5) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		node* v;
		v = cm.search(name, cm.getRoot(cm.getCurrent())->getsubnodes());
		if (v != nullptr) {
			cout << "\nPath: " << v->getPath() << endl;
		}
		else
			cout << "Node Does Not Exist!" << endl;
	}
	else if (choice == 6) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		cm.rm(name);
	}
	else if (choice == 7) {
		string oldName;
		cout << "\nEnter Old Name: ";
		getline(cin, oldName);
		string newName;
		cout << "\nEnter New Name: ";
		getline(cin, newName);
		cm.rename(oldName, newName);
	}
	else if (choice == 8) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		cm.zipNode(name);
	}
	else if (choice == 9) {
		string name;
		cout << "\nEnter Name: ";
		getline(cin, name);
		cm.unzip(name);
	}
	else if (choice == 0) {
		return choice;
	}
	cout << "\n\nClear?\t Yes: 1\tNo: 2\t: ";
	secondaryChoice = inputNum('1', '2');
	if (secondaryChoice == 1) {
		system("cls");
	}
	return choice;
}