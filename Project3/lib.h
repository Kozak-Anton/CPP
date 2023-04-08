#pragma once
#include "Text.h"

const int max_init_text = 3;              //Max starting text enties

Text* write_text(Text* , int*);           //returns array of user input entries of text
void read_text(Text* , int);              //outputs text entrie
void append_text(Text* , int);            //adds new lines of text to selected entrie
void find_vowel(Text* , int);             //find text entrie with max amaunt of vowels