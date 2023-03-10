#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_INPUT=60;
static const char* SEPARATOR = ".,;";

struct Book {
	char title[MAX_INPUT];
	char author[MAX_INPUT];
	char language[MAX_INPUT];
	int year;
	int num;
};

void write_catalogue(string);
void read_catalogue(string);
void append_catalogue(string);
bool name_search(string, char*);