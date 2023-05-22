#include "FlightLog.h"
using namespace std;

void FlightLog::format_check(string line){

	istringstream format(line);
	string number, destination, date, departure, extra;
	format >> number >> destination >> date >> departure;
	
	if (line.empty()) return;
	for (char& ch : number) {
		if (!isdigit(ch)) throw runtime_error("Incorrect flight number");
	}

	if (destination.empty()) throw runtime_error("Incorrect or missing destination address");
	for (char& ch : destination) {
		if (!isalpha(ch)) throw runtime_error("Incorrect or missing destination address");
	}

	int i = 0;
	int day, mon, year;
	day = mon = year = -1;
	day = get_format_number(date, ':', i);
	mon = get_format_number(date, ':', i);
	year = get_format_number(date, ':', i);
	if (year < 2000 || year > 2050 ) throw runtime_error("Incorrect year input");
	if (mon > 12 || mon < 1) throw runtime_error("Incorrect month input");
	switch (mon) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day < 1 || day > 31) throw runtime_error("Incorrect date input");
		break;
	case 2:
		if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
			if (day < 1 || day > 29) throw runtime_error("Incorrect date input");
		}
		else if (day < 1 || day > 28) throw runtime_error("Incorrect date input");
		break;
	default:
		if (day < 1 || day > 30) throw runtime_error("Incorrect date input");
		break;
	}

	i = 0;
	int hours, minutes;
	hours = minutes = -1;
	hours = get_format_number(departure, ':', i);
	minutes = get_format_number(departure, ':', i);
	if (hours < 0 || hours>23 || minutes < 0 || minutes > 59) throw runtime_error("Incorrect time input");

}

int FlightLog::get_format_number(string line,char sep, int& pos) {
	int temp = 0;
	while (pos<line.length() && line[pos] != sep) {
		if (!isdigit(line[pos])) throw runtime_error("Incorrect or missing date format");
		temp = temp * 10 + line[pos]- '0';
		++pos;
	}
	++pos;
	return temp;
}

void FlightLog::input_log(){
	try
	{
		ofstream file(log_file_name);
		string line;

		cout << "Input flight log contents in format: Flight_number Destination Date(dd.mm.yyyy) Departure(hh.mm)" << endl;
		while(getline(cin, line)) {
			if (line.empty())
				break;
			format_check(line);
			file << line << "\n";
		}
		cout << "Successfully wrote entries to log" << endl;
		return;
	}
	catch (runtime_error err) {
		cerr << "Couldn`t write current line. Suspending input." << endl;
		cerr << "Cause of error: " << err.what() << endl;
		cout << endl;
		cin.seekg(0, ios::end);
		cin.clear();
	}
}

void FlightLog::append_log(){
	try
	{
		ofstream file(log_file_name, ios::app);
		string line;

		cout << "Add entries to flight log in format: Flight_number Destination Date(dd.mm.yyyy) Departure(hh.mm)" << endl;
		while (getline(cin, line)) {
			if (line.empty())
				break;
			format_check(line);
			file << line << "\n";
		}
		cout << "Successfully added entries to log" << endl;
		return;
	}
	catch (runtime_error err) {
		cerr << "Couldn`t write current line. Suspending input." << endl;
		cerr << "Cause of error: " << err.what() << endl;
		cout << endl;
		cin.seekg(0, ios::end);
		cin.clear();
	}
}

void FlightLog::read_log(){
	ifstream file(log_file_name);
	string line;

	cout << "All flights in log: " << endl;
	while (getline(file, line)) {
		cout << line << endl;
	}
	cout << endl;
}

void FlightLog::find_log(){
	ifstream file(log_file_name);
	string line_log, line_input, compare_input, compare_log;
	bool found = false;

	cout << "Input paremeters for search: ";
	getline(cin, line_input);
	while (getline(file, line_log)) {
		bool includes = true;
		istringstream search_log(line_log);
		istringstream search_input(line_input);
		while (search_input >> compare_input) {
			while (search_log >> compare_log) {
				if (compare_input == compare_log) {
					includes = true;
					break;
				}
				else {
					includes = false;
				}
			}
		}
		if (includes) {
			found = true;
			cout << line_log << endl;
		}
		
	}
	if (!found)
		cout << "No matches for given input." << endl << endl;
	else
		cout << endl;
}
