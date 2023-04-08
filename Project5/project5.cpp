#include "lib.h"

int main() {
	int bin_num = 0, oct_num = 0;
	TIntNumber* array2 = nullptr;                                               //array of numbers in base 2
	TIntNumber* array8 = nullptr;                                               //array of numbers in base 8

	cout << "Command list:\n";
	cout << "write[2|8] - write array in base2/8\n";
	cout << "read[2|8] - read array in base2/8\n";
	cout << "array[2|8][++|--] - increment/decrement array in base2/8\n";
	cout << "find - find max number in arrays\n";
	cout << "end - end the program\n\n";

	string command;
	cout << "Command: ";
	while (getline(cin, command)) {
		if (command == "write2") {
			delete[] array2;
			array2 = write_array(bin_num, 2);
			cin.ignore();
		}
		else if (command == "write8") {
			delete[] array8;
			array8 = write_array(oct_num, 8);
			cin.ignore();
		}
		else if (command == "read2")
			read_array(array2, bin_num);
		else if (command == "read8")
			read_array(array8, oct_num);
		else if (command == "array2++")
			increment_array(array2, bin_num);
		else if (command == "array2--")
			decrement_array(array2, bin_num);
		else if (command == "array8++")
			increment_array(array8, oct_num);
		else if (command == "array8--")
			decrement_array(array8, oct_num);
		else if (command == "find") {
			cout << "Min number in both arrays is: ";
			cout << find_min(array2, bin_num, array8, oct_num);
			cout << "\n";
		}
		else if (command == "end")
			break;
		cout << "Command: ";
	}

	delete[] array2;
	delete[] array8;
}