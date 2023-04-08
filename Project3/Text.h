#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Text {
	const char* vowel_list = "aeiouyAEIOUY";                      //list of vowels
	const int max_init = 3;                                       //max starting lines of text
	int lines;                                                    //number of actual lines of text
	string* text;                                                 //text consists of array of lines

public:
	Text() : lines(0), text(new string[max_init]) {};
	~Text();
	void input();
	void append();
	void set_text(string*, int);
	string* get_text();
	int count_vowels() const;
	int get_lines() const;
	void read() const;
};
