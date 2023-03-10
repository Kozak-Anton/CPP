#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char SEPARATORS[] = " ,.;";                //Separator characters


void write_input(string);                        //Function writes input lines to text file
void read_file(string);                          //Function reads lines from text file
void append_input(string);                       //Function appends lines to end of text file
void update_output(string, string, string);      //Function defines new word mask
void edit_mask(string&);                         //Function edits text from input_name using mask, writes it in output_name
