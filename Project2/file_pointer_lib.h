#pragma once

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_INPUT = 10000;                   //Max input per string
static const char* SEPARATOR = ".,;";          //Name separators

struct Book {
	char title[MAX_INPUT];                     //Book title
	char author[MAX_INPUT];                    //Author(s) name
	char language[MAX_INPUT];                  //Book language
	int year;                                  //Year of publishing
	int num;                                   //Copies in stock
}; 

void write_catalogue(char* );                  //Input catalogue in file
void read_catalogue(char* );                   //Read catalogue from file
void append_catalogue(char* );                 //Append entries to end of file
void search_author(char* );                    //Read number of copies per title for author 
void filter_author(char* , char* );            //Write sorted catalogue of books of an author in file
