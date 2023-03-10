#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_INPUT=100;                       //Max input per string
static const char* SEPARATOR = ".,;";          //Name separators

struct Book {                                  
	char title[MAX_INPUT];                     //Book title
	char author[MAX_INPUT];                    //Author(s) name
	char language[MAX_INPUT];                  //Book language
	int year;                                  //Year of publishing
	int num;                                   //Copies in stock
};

void write_catalogue(string);                  //Input catalogue in file
void read_catalogue(string);                   //Read catalogue from file
void append_catalogue(string);                 //Append entries to end of file
void search_author(string);                    //Read number of copies per title for author 
void filter_author(string, string);            //Write sorted catalogue of books of an author in file