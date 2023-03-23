#include "file_stream_lib.h"

//Input catalogue in file
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
		cout << "Author(s): ";
		cin.getline(temp.author, MAX_INPUT);
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

//Append entries to end of file
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
		cin.getline(temp.author, MAX_INPUT);
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

//Returns true if name is part of line, othewise returns false 
bool name_search(string name, char* line) {
	bool char_is_sep(char);

	bool cons = false;
	bool prev = false;
	string str = line;
	str = "."+str+".";
	int i = 0;

	while ((i = str.find(name, i)) != string::npos) {

		for (int j = i-1; j >= 0; j--) {
			if (char_is_sep(str[j])) {
				prev = true;
				break;
			}
			else if (str[j] != ' ') {
				prev = false;
				break;
			}
		}
		i = i + name.length();

		if (prev) {
			for (; i < str.length(); i++) {
				if (char_is_sep(str[i])) {
					cons = true;
					return cons;
				}
				else {
					break;
				}
			}
		}
	}

	return cons;
}

//Returns ture if char is a separator, othrwise returns false
bool char_is_sep(char srch) {
	for (int i = 0; i < strlen(SEPARATOR); i++) {
		if (SEPARATOR[i] == srch) {
			return true;
		}
	}
	return false;
}

//Read catalogue from file
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

//Read number of copies per title for author 
void search_author(string file) {
	bool name_search(string, char*);
	Book temp;
	string name= " ";

	cout << "Input author name: ";
	cin.ignore();
	getline(cin, name);
	fstream catalogue(file, ios::in | ios::binary);

	while (catalogue.read((char*)&temp, sizeof(Book))) {
		if (name_search(name, temp.author)) {
			cout << "Title: "<<temp.title<<".   Copies in stock: "<<temp.num<<".\n";
		}
	}
	cout << "\n";
}

//Write sorted catalogue of books of an author in file
void filter_author(string input_file, string output_file) {
	bool name_search(string, char*);
	void sort_by_author(string, string);
	Book temp;
	string name = " ";

	cout << "Input author name: ";
	cin.ignore();
	getline(cin, name);
	fstream catalogue(input_file, ios::in | ios::binary);
	fstream sorted_catologue(output_file, ios::out | ios::binary | ios::trunc);

	while (catalogue.read((char*) &temp, sizeof(Book))) {
		if (name_search(name, temp.author)) {
			sorted_catologue.write((char*) &temp, sizeof(Book));
		}
	}

	catalogue.close();
	sorted_catologue.close();

	sort_by_author(name, output_file);

}

//Sorts catalogue file based on bool titles
void sort_by_author(string name, string file) {
	Book temp1;
	Book temp2;

	fstream catalogue(file, ios::in | ios::out | ios::binary);
	

	for (int i = 0; i < catalogue.tellg() / sizeof(Book) - 1; i++) {

		for (int j = 0; i < catalogue.tellg() / sizeof(Book) - 1 - i; j++) {

			catalogue.seekg(j * sizeof(Book), ios::beg);
			catalogue.read((char*)&temp1, sizeof(Book));
			catalogue.read((char*)&temp2, sizeof(Book));

			if (temp1.title > temp2.title) {

				catalogue.seekg(j * sizeof(Book), ios::beg);
				catalogue.write((char*)&temp2, sizeof(Book));
				catalogue.write((char*)&temp1, sizeof(Book));
			}
			catalogue.clear();
		}
		catalogue.clear();
	}

	catalogue.close();
}