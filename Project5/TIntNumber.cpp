#include "lib.h"
//sets number values
void TIntNumber::set_number() {
	cout << "Input base(up to 36): ";
	while (true) {
		cin >> base;
		if (base > 1 && base < 36)
			break;
	}
	cout << "Input number in base: ";
	cin >> number_rep;

	convert_base_to_10();
}
//returns number value
int TIntNumber::get_number() const {
	return number;
}
//outputs number in base and in base 10
void TIntNumber::read_number() const{
	cout << "Number: " << number_rep <<"(base "<<base<<") = "<< number <<"(base 10)\n";
}
//increments number value
void TIntNumber::operator++() {
	number++;
	convert_10_to_base();
}
//increments number value
void TIntNumber::operator++(int unused) {
	number++;
	convert_10_to_base();
}
//decrements number value
void TIntNumber::operator--() {
	number--;
	convert_10_to_base();
}
//decrements number value
void TIntNumber::operator--(int unused) {
	number--;
	convert_10_to_base();
}
//updates number representation in base
void TIntNumber::convert_10_to_base() {
	int temp = number;
	int i = 0;
	int sign = 1;

	number_rep.clear();
	if (temp < 0) {
		sign = -1;
		temp *= -1;
	}
	while (temp > 0) {
		if (temp % base < 10)
			number_rep += (char)(temp % base + '0');
		else 
			number_rep += (char)(temp % base - 10 + 'A');
		temp /= base;
	}
	reverse(number_rep.begin(), number_rep.end());

	if (sign < 0)
		number_rep = "-" + number_rep;
}
//defines number based on representation and base
void TIntNumber::convert_base_to_10() {
	bool added = false;
	char max;
	if (base > 10) {
		max = base - 11 + 'A';
		added = true;
	}
	else {
		max = base + '0';
	}

	int i = 0;
	int sign = 1;
	if (number_rep[0] == '-') {
		sign = -1;
		i++;
	}
	else if (number_rep[0] == '+') {
		i++;
	}
	if (i == 1 && number_rep.length() == 1) {
		number_rep = "0";
		return;
	}

	for (; i < number_rep.length(); i++) {
		if (added) {
			if (isdigit(number_rep[i]))
				number = number * base + number_rep[i] - '0';
			else if (number_rep[i] >= 'A' && number_rep[i] <= max)
				number = number * base + number_rep[i] - 'A' + 10;
		}
		else if (number_rep[i] >= '0' && number_rep[i] <= max) {
			number = number * base + number_rep[i] - '0';
		}
		else {
			number_rep = "0";
			return;
		}
	}
	number *= sign;
}

