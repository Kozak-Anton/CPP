#include "Text.h"


void Text::input() {
	string line, * temp;
	int i = 0;
	int size = max_init;
	while (getline(cin, line) && !line.empty()) {
		
		if (i > size-1) {
			temp = new string[size];
			for (int j = 0; j < i; j++) 
				temp[j] = text[j];
			delete[] text;

			text = new string[size *= 2];
			for (int j = 0; j < i; j++) 
				text[j] = temp[j];
			delete[] temp;
		}
		text[i++] = line;
	}
	lines = i;

}

void Text::append() {
	string line, * temp;
	int i = lines;
	int size = lines;
	while (getline(cin, line) && !line.empty()) {

		if (i > size - 1) {
			temp = new string[size];
			for (int j = 0; j < i; j++)
				temp[j] = text[j];
			delete[] text;

			size = ceil(size * 1.25);
			text = new string[size];
			for (int j = 0; j < i; j++)
				text[j] = temp[j];
			delete[] temp;
		}
		text[i++] = line;
	}
	lines = i;
}

const int Text::count_vowels() {
	int vowels = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < text[i].length(); j++) {
			if (strchr(vowel_list, text[i][j]) != NULL)
				vowels++;
		}
	}
	return vowels;
}

string* Text::get_text() {
	string* temp = new string[lines];
	for (int i = 0; i < lines; i++) {
		temp[i] = text[i];
	}
	return temp;
}

void Text::set_text(string* new_text, int new_lines) {
	delete[] text;
	text = new_text;
	lines = new_lines;
}

const void Text::read() {
	for (int i = 0; i < lines; i++) {
		cout << text[i] << "\n";
	}
	cout << "\n";
}

const int Text::get_lines() {
	return lines;
}

Text::~Text() {
	delete[] text;
}