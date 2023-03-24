#include "file_pointer_lib.h"

//Input catalogue in file
void write_catalogue(char* name) {
	int books;
	Book temp;

	FILE* fp;
	fopen_s(&fp, name, "wb");

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

		fwrite(&temp, sizeof(Book), 1, fp);
	}

	fclose(fp);
}

//Read catalogue from file
void read_catalogue(char* name) {
	int entry = 1;
	Book temp;

	FILE* fp;
	fopen_s(&fp, name, "rb");

	cout << "Book selection: \n";
	while (fread(&temp, sizeof(Book), 1, fp) > 0) {

		cout << "Entry #" << entry << "\n";
		cout << "Title: " << temp.title << "\n";
		cout << "Author: " << temp.author << "\n";
		cout << "Language: " << temp.language << "\n";
		cout << "Year of publishing: " << temp.year << "\n";
		cout << "Copies in stock: " << temp.num << "\n\n";
		entry++;
	}

	fclose(fp);
}

//Append entries to end of file
void append_catalogue(char* name) {
	int books;
	Book temp;

	FILE* fp;
	fopen_s(&fp, name, "ab");

	cout << "Input number of books to add: ";
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

		fwrite(&temp, sizeof(Book), 1, fp);
	}

	fclose(fp);
}

//Returns true if name is part of line, othewise returns false 
bool name_search(char* line, char* name) {
	char* temp;
	temp = line;

	while ((temp = strstr(temp, name)) != NULL) {
		temp += strlen(name);
		while (*temp == ' ')
			temp++;

		if (strchr(SEPARATOR, *temp) != NULL || *temp == '\0') {
			return true;
		}
	}

	return false;
}

//Read number of copies per title for author 
void search_author(char* file) {
	char name[MAX_INPUT];
	Book temp;
	FILE* fp;
	fopen_s(&fp, file, "rb");

	cout << "Input author name: ";
	cin.ignore();
	cin.getline(name, MAX_INPUT);

	while (fread(&temp, sizeof(Book), 1, fp) > 0) {
		if (name_search(temp.author, name)) {
			cout << "Title: " << temp.title << ".   Copies in stock: " << temp.num << ".\n";
		}
	}
	cout << "\n";

	fclose(fp);
}

//Write sorted catalogue of books of an author in file
void filter_author(char* input_file, char* output_file) {
	bool name_search(char*, char*);
	void sort_by_author(char*, char*);
	Book temp;
	char name[MAX_INPUT];

	FILE* fr;
	FILE* fw;
	fopen_s(&fr, input_file, "rb");
	fopen_s(&fw, output_file, "wb");

	cout << "Input author name: ";
	cin.ignore();
	cin.getline(name, MAX_INPUT);

	while (fread(&temp, sizeof(Book), 1, fr) > 0) {
		if (name_search(temp.author, name)) {
			fwrite(&temp, sizeof(Book), 1, fw);
		}
	}
	
	fclose(fr);
	fclose(fw);

	sort_by_author(name, output_file);

}

//Sorts catalogue file based on bool titles
void sort_by_author(char* name, char* file) {
	Book temp1, temp2;
	FILE* fp;
	int i, j, len;

	fopen_s(&fp, file, "rb+");
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(Book);
	
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i ; j++) {
			fseek(fp, j * sizeof(Book), SEEK_SET);
			fread(&temp1, sizeof(Book), 1, fp);
			fread(&temp2, sizeof(Book), 1, fp);

			if (strcmp(temp1.title, temp2.title) > 0) {
				fseek(fp, j * sizeof(Book), SEEK_SET);
				fwrite(&temp2, sizeof(Book), 1, fp);
				fwrite(&temp1, sizeof(Book), 1, fp);

			}
		}

	}

	fclose(fp);
}


