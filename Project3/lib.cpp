#include "lib.h"

int write_text(Text* list) {
	cout << "Empty line stops text input for an entrie\n";
	cout << "Empty line as first line of entrie stops all text input\n";
	cin.ignore();

	Text* temp;
	int i = 0;
	int size = max_init_text;

	while (true) {

		if (i > size - 1) {
			temp = new Text[size];
			for (int j = 0; j < i; j++)
				temp[j].set_text(list[j].get_text(), list[j].get_lines());
			delete[] list;

			list = new Text[size *= 2];
			for (int j = 0; j < i; j++)
				list[j].set_text(temp[j].get_text(), temp[j].get_lines());
			delete[] temp;
		}

		cout << "Entry #" << i + 1 << "\n";
		list[i].input();
		if (list[i].get_lines() == 0)
			break;
		
		i++;
	}
	cout << "Input ended\n\n";

	return i;
}

void read_text(Text* list, int num) {
	for (int i = 0; i < num; i++) {
		cout << "Entrie #" << i + 1 << "\n";
		list[i].read();
	}
}

void append_text(Text* list, int num) {
	int app_num;

	if (num == 0) {
		cout << "No entries";
		return;
	}

	while (true) {
		cout << "Input which entrie to append(0 to exit) : ";
		cin >> app_num;

		if (app_num < 1 || app_num > num)
			return;

		cin.ignore();
		list[app_num-1].append();
	}

}

void find_vowel(Text* list, int num) {
	int max_text = 0;
	int max_vow = 0;

	if (num == 0) {
		cout << "No entries\n";
		return;
	}
	
	for (int i = 0; i < num; i++) {
		if (list[i].count_vowels() >= max_vow) {
			max_vow = list[i].count_vowels();
			max_text = i;
		}
	}

	cout << "Text entrie " << max_text + 1 << " has maximum of "<<max_vow<<" vowels\n";
	list[max_text].read();
}
