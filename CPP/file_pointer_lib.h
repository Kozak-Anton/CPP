#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#define MAXLEN 1000                                
using namespace std;

const char SEPARATORS[] = " ,.;";                  //Separator characters

void write_input(char* );                          //Function writes input lines to text file
void read_file(char* );                            //Function reads lines from text file
void append_input(char* );                         //Function appends lines to end of text file
void edit_mask(char*);                             //Function defines new word mask
void update_output(char* , char* , char* );        //Function edits text from input_name using mask, writes it in output_name