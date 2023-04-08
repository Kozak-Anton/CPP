#include "lib.h"

//outputs ring  data
void read_ring(Ring ring) {
	cout << "Ring center at (" << ring.get_x() << ", " << ring.get_y() << ") ";
	cout << "R = " << ring.get_R() << ", " << "r = " << ring.get_r() << "\n";
}

//reads command from input
arguments read_command(int& num, int& multiplier) {
	string line;
	cout << "Input command: ";
	cin >> line;

	multiplier = 0;
	num = 0;
	if (line == "end") {
		return end_prog;
	}
	if (line == "find") {
		return find_max;
	}
	if (line.find("readC")==0 && isdigit(line[5]) && line.length() == 6) {
		num = line[5]-'0';
		return read;
	}
	if (line.find("++C")==0 && isdigit(line[3]) && line.length() == 4) {
		num = line[3]-'0';
		return prefix;
	}
	if (line.find("++") == 2 && line[0]=='C' && isdigit(line[1]) && line.length() == 4) {
		num = line[1]-'0';
		return postfix;
	}
	if (line.find("*=") == 2 && line[0] == 'C' && isdigit(line[1]) && line.length() >= 4) {
		num = line[1]-'0';
		for (int i = 4; i < line.length(); i++) {
			if (isdigit(line[i]))
				multiplier = multiplier * 10 + (line[i]-'0');
			else {
				return error;
			}
		}
		return multiply;
	}

	return error;
}

//finds ring with max width
void find_max_ring(Ring C1, Ring C2, Ring C3) {
	if (C1.get_width() > C2.get_width() && C1.get_width() > C3.get_width()) 
		cout << "Max width ring is C1: width = " << C1.get_width()<<"\n";
	else if (C2.get_width() > C3.get_width())
		cout << "Max width ring is C2: width = " << C2.get_width() << "\n";
	else
		cout << "Max width ring is C3: width = " << C3.get_width() << "\n";

}