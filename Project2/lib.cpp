#include "lib.h"

void write_catalogue(string name) {
	int books;
	Book temp;
	fstream catalogue(name, ios::out | ios::binary|ios::trunc);

	cout << "Input number of books in catalog: ";
	cin >> books;
	

	for (int i = 0; i < books; i++) {
		cin.ignore();
		cout << "Title: ";
		cin.getline(temp.title, MAX_INPUT);
		cout << "Author: ";
		cout << "Language: ";
		cin.getline(temp.language, MAX_INPUT);
		cout << "Year of publishing: ";
		cin >> temp.year;
		cout << "Copies in stock: ";
		cin >> temp.num;
		cout << "\n";

		catalogue.write((char*) &temp, sizeof(Book));
	}

	catalogue.close();

}

void append_catalogue(string name) {
	int books;
	Book temp;
	fstream catalogue(name, ios::out | ios::binary | ios::app);

	cout << "Input number of books to add: ";
	cin >> books;

	for (int i = 0; i < books; i++) {
		cin.ignore();
		cout << "Title: ";
		cin.getline(temp.title, MAX_INPUT);
		cout << "Author: ";
		cout << "Language: ";
		cin.getline(temp.language, MAX_INPUT);
		cout << "Year of publishing: ";
		cin >> temp.year;
		cout << "Copies in stock: ";
		cin >> temp.num;
		cout << "\n";

		catalogue.write((char*)&temp, sizeof(Book));
	}

	catalogue.close();
}

bool name_search(string name, char* line) {
	bool char_is_sep(char);
	int temp=0;
	bool cons=false;
	for (int i = 0; i < MAX_INPUT; i++) {
		if (name[0] == line[i]) {
			cons = true;
			for (int j = 0; j < name.length(); j++, i++) {
				if (name[j] != line[i]) {
					cons = false;
					break;
				}
			}
			if (cons) {
				for (; i < MAX_INPUT; i++) {
					if (!char_is_sep(line[i]) && !isspace(line[i])) {
						cons = false;
						break;
					}
					else if (char_is_sep(line[i])) {
						return cons;
					}
				}
			}
		}
	}
	return cons;
}

bool char_is_sep(char srch) {
	for (int i = 0; i < strlen(SEPARATOR); i++) {
		if (SEPARATOR[i] == srch) {
			return true;
		}
	}
	return false;
}

void read_catalogue(string name) {
	int entry = 1;
	Book temp;
	fstream catalogue(name, ios::in | ios::binary);

	cout << "Book selection: \n";
	while (catalogue.read((char*)&temp, sizeof(Book))) {
		
		cout << "Entry #" << entry << "\n";
		cout << "Title: " << temp.title << "\n";
		cout << "Author: " << temp.author << "\n";
		cout << "Language: " << temp.language << "\n";
		cout << "Year of publishing: " << temp.year << "\n";
		cout << "Copies in stock: " << temp.num << "\n\n";
		entry++;

	}

	catalogue.close();
}