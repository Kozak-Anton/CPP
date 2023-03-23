#pragma once

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_INPUT = 10000;
static const char* SEPARATOR = ".,;";     

struct Book {
	char title[MAX_INPUT];                     //Book title
	char author[MAX_INPUT];                    //Author(s) name
	char language[MAX_INPUT];                  //Book language
	int year;                                  //Year of publishing
	int num;                                   //Copies in stock
}; 

void write_catalogue(char* );
void read_catalogue(char* );
void append_catalogue(char* );
void search_author(char* );
void filter_author(char* , char* );
