//#include "lib.h"
#include "QueueEditor.h"

int main() {
	QueueEditor queue;
	string command;

	cout << "Command list: " << endl;
	cout << "make [type] [size] - creates Queue for given type and size (Allowed types: int, char, string)" << endl;
	cout << "push [item] - add item of coresponding type to Queue" << endl;
	cout << "pop - take item from Queue" << endl;
	cout << "clear - empty contents of Queue" << endl;
	cout << "print - output contents of Queue" << endl;
	cout << "end - end the program\n" << endl;

	do {
		cout << "Command: ";
		cin >> command;
		if (command == "make") queue.make(cin);
		else if (command == "push") queue.push(cin);
		else if (command == "pop") queue.pop(cout);
		else if (command == "clear") queue.clear();
		else if (command == "print") queue.print(cout);
		else if (command != "end") cout << "incorrect input" << endl;
	} while (command != "end");
}