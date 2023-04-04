#include "lib.h"

int main() {
	Ring C1;
	Ring C2(C1);
	Ring C3(2, 4, 3, -3);

	cout << "Created 3 ring objects with r-inner radius, R-outer radius:\n";
	cout << "C1 ";
	read_ring(C1);
	cout << "C2 ";
	read_ring(C2);
	cout << "C3 ";
	read_ring(C3);
	cout << "\nList of command to operate with rings:\n";
	cout << "C++ - add 1 to outer radius\n";
	cout << "++C - add 1 to inner radius\n";
	cout << "C*=X - multiply outer radius by X(integer)\n";
	cout << "find - find a ring with max width(R-r)\n";
	cout << "readC - read values of a ring\n";
	cout << "end - stop program\n\n";

	arguments command;
	int ring_num, multiplier;
	
	while (command = read_command(ring_num, multiplier)) {
		switch (command){
		case error:
			cout << "Wrong input format\n";
			break;
		case read:
			switch (ring_num) {
			case 1:
				read_ring(C1);
				break;
			case 2:
				read_ring(C2);
				break;
			case 3:
				read_ring(C3);
				break;
			}
			break;
		case prefix:
			switch (ring_num) {
			case 1:
				++C1;
				break;
			case 2:
				++C2;
				break;
			case 3:
				++C3;
				break;
			}
			break;
		case postfix:
			switch (ring_num) {
			case 1:
				C1++;
				break;
			case 2:
				C2++;
				break;
			case 3:
				C3++;
				break;
			}
			break;
		case multiply:
			switch (ring_num) {
			case 1:
				C1 *= multiplier;
				break;
			case 2:
				C2 *= multiplier;
				break;
			case 3:
				C3 *= multiplier;
				break;
			}
			break;
		case find_max:
			find_max_ring(C1, C2, C3);
			break;
		}
	}
	}

