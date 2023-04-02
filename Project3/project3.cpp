#include "lib.h"

int main()
{
	Text* entrie_list = new Text[max_init_text];
	int num_entries = 0;
	string command = "a";

	cout << "Command list:\n";
	cout << "write - add new text enties to the list\n";
	cout << "read - outputs all text enties\n";
	cout << "append - adds new line to the text entire\n";
	cout << "end - stop the program\n\n";

	while (command != "end") {
		cout << "Input command: ";
		cin >> command;
		if (command == "write") {
			num_entries = write_text(entrie_list);
		}
		else if (command == "read") {
			read_text(entrie_list, num_entries);
		}
		else if (command == "append") {
			append_text(entrie_list, num_entries);
		}
		else if (command == "find") {
			find_vowel(entrie_list, num_entries);
		}
		else if (command != "end") {
			cout << "Wrong input\n";
		}
	}

	delete[] entrie_list;
}