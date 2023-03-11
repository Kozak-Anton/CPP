#include "lib.h"

//Function writes input lines to text file
void write_input(string name) {
	string line = "a";

	cout << "Input file contents bellow (empty line to stop writing): \n";
	fstream input_file(name, ios::out|ios::trunc);
	while (true) {
		getline(cin, line);
		if (line.empty())
			break;
		input_file << line << " \n";
	}
	input_file.close();

}

//Function reads lines from text file
void read_file(string name) {
	string line;

	cout << "File contents: \n";
	fstream file(name, ios::in);
	while (true) {
		getline(file, line);
		if (file.eof())
			break;
		cout << line << "\n";
	}
	file.close();
}

//Function appends lines to end of text file
void append_input(string name) {
	string line = "a";
	cout << "Add line to end of file bellow(empty line to stop writing): \n";
	fstream input_file(name, ios::out|ios::app);
	while (true) {
		getline(cin, line);
		if (line.empty())
			break;
		input_file << line << " \n";
	}
	input_file.close();
}

//Function defines new word mask
void edit_mask(string &mask) {
	int mask_test;

	cout << "Input mask (previous mask = \"" << mask << "\"): ";
	while (true) {
		cin >> mask;
		mask_test = mask.find("*");
		if (mask.find("*", mask_test + 1) == string::npos){
			cout << "\n";
			break;
	}
		else
			cout << "Wrong mask format\n";
	}
}

//Function edits text from input_name using mask, writes it in output_name
void update_output(string input_name, string output_name, string mask) {
	string edit_line(string, string);
	fstream input_file(input_name, ios::in);
	fstream output_file(output_name, ios::out|ios::trunc);
	string line, new_line;

	while (!input_file.eof()) {
		getline(input_file, line);
		new_line = edit_line(line, mask);
		if (!new_line.empty())
			output_file << new_line << " \n";
	}

	input_file.close();
	output_file.close();
}

//Function returns string edited from line using mask
string edit_line(string line, string mask) {
	bool check_mask(string, string);

	bool edited = false;
	int start=0;
	int	end=0;
	string word;

	while (true) {
		start = line.find_first_not_of(SEPARATORS, end);
		end = line.find_first_of(SEPARATORS, start);
		if (start < 0)
			break;
		word = line.substr(start, end - start);

		if (check_mask(word, mask) && word[0] != '(' && word[word.length() - 1] != ')') {
			line.erase(start, word.length());
			line.append("(" + word + ") ");
			end = start;

			edited = true;
		}
		start = end;
	}

	if (edited)
		return line;
	else
		return "";
}

//Functions returns true is word fits with mask, returns false otherwise
bool check_mask(string word, string mask) {
	int mask_pos;
	string compare, compare_add;

	if (mask == "*") {
		return true;
	}
	else if (mask.find("*") == string::npos) {
		if (word == mask) 
			return true;
	}
	else if (mask[0] == '*') {
		compare = mask.substr(1, mask.length());
		if (word.rfind(compare) == word.length() - mask.length()+1)
			return true;
	}
	else if (mask[mask.length()-1] == '*') {
		compare = mask.substr(0, mask.length()-1);
		if (word.find(compare) == 0)
			return true;
	}
	else {
		mask_pos = mask.find('*');
		compare = mask.substr(0, mask_pos);
		compare_add = mask.substr(mask_pos + 1, mask.length());
		if (word.find(compare) == 0 && word.rfind(compare_add) == word.length() - compare_add.length())
			return true;
	}

	return false;

}