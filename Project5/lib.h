#pragma once

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class TIntNumber {
protected:
	int number;                                                //number in base 10
	int base;                                                  //initial number base
	string number_rep;                                         //representation of number in base
	void convert_10_to_base();                                 //updates number representation in base
	void convert_base_to_10();                                 //defines number based on representation and base
public:
	TIntNumber() : number_rep("0"), number(0), base(10) {};
	void virtual set_number();                                 //sets number values
	void read_number() const;                                  //outputs number in base and in base 10
	int get_number() const;                                    //returns number value
	void operator++();                                         //increments number value
	void operator++(int);                                      //increments number value
	void operator--();                                         //decrements number value
	void operator--(int);                                      //decrements number value
}; 

class TIntNumber2:public TIntNumber {
public:
	TIntNumber2() {
		base = 2;                                              //new base
	}
	void virtual set_number() {                                //sets number values(base is always 2)
		cout << "Input number in base 2: ";
		cin >> number_rep;
		convert_base_to_10();
	}
};

class TIntNumber8 :public TIntNumber {
public:
	TIntNumber8() {
		base = 8;                                              //new base
	}
	void virtual set_number() {                                //sets number values(base is always 8)
		cout << "Input number in base 8: ";
		cin >> number_rep;
		convert_base_to_10();
	}
};

TIntNumber* write_array(int&, int );                           //inputs array of numbers in set base
void read_array(TIntNumber*, int);                             //read array of numbers
void increment_array(TIntNumber*, int);                        //increments all numbers in array
void decrement_array(TIntNumber*, int);                        //decrements all numbers in array
int find_min(TIntNumber*, int, TIntNumber*, int);              //finds min number amoung 2 arrays