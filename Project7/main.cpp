#include "lib.h"
#include "FlightLog.h"

using namespace std;

int main(){
	FlightLog log(FLIGHT_LOG_FILE);
	string command;

	cout << "Command list:" << endl;
	cout << "write - write entries to log" << endl;
	cout << "append - append entries to log" << endl;
	cout << "read - read entries from log" << endl;
	cout << "find - find flight based of input" << endl;
	cout << "end - close the program" << endl << endl;

	do {

		cout << "command: ";
		cin >> command;
		cin.seekg(0, ios::end);
		cin.clear();
		if (command == "write")
			log.input_log();
		else if (command == "append")
			log.append_log();
		else if (command == "read")
			log.read_log();
		else if (command == "find")
			log.find_log();
		else if (command != "end")
			cout << "Incorrect input." << endl;
	} while (command != "end");
}