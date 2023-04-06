#pragma once

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class TIntNumber {
protected:
	int number;
	int base;
	string number_rep;
	void convert_10_to_base();
	void convert_base_to_10();
public:
	TIntNumber() : number_rep("0"), number(0), base(10) {};
	void virtual set_number();
	void read_number() const;
	int get_number() const;
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
};

class TIntNumber2:public TIntNumber {
public:
	TIntNumber2() {
		base = 2;
	}
	void virtual set_number() {
		cout << "Input number in base 2: ";
		cin >> number_rep;
		convert_base_to_10();
	}
};

class TIntNumber8 :public TIntNumber {
public:
	TIntNumber8() {
		base = 8;
	}
	void virtual set_number() {
		cout << "Input number in base 8: ";
		cin >> number_rep;
		convert_base_to_10();
	}
};

TIntNumber* write_array(int&, int );
void read_array(TIntNumber*, int);
void increment_array(TIntNumber*, int);
void decrement_array(TIntNumber*, int);
int find_min(TIntNumber*, int, TIntNumber*, int);