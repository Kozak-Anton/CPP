#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//FlightLog: class is a representaion of list of flights following set format
class FlightLog {
	const std::string log_file_name;										//file with entries
	void format_check(std::string);											//thows exeption specifying format error if present
	int get_format_number(std::string , const char , int& );				//gets a number from line starting from position and to separator

public:
	FlightLog(std::string new_file_name) : log_file_name(new_file_name) {};
	void input_log();														//write a log file
	void append_log();														//add entries to log file
	void read_log();														//output entries from log file
	void find_log();														//find entries with specified values

};

