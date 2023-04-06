#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Text {
	const char* vowel_list = "aeiouyAEIOUY";
	const int max_init = 3;
	int lines;
	string* text;

public:
	Text() : lines(0), text(new string[max_init]) {};
	~Text();
	void input();
	void append();
	void set_text(string*, int);
	string* get_text();
	const int count_vowels();
	const int get_lines();
	const void read();
};
