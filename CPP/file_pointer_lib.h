#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#define MAXLEN 1000
using namespace std;

const char SEPARATORS[] = " ,.;";

void write_input(char* );
void read_file(char* );
void append_input(char* );
void edit_mask(char*);
void update_output(char* , char* , char* );