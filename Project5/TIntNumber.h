#pragma once
#include <string>
#include <iostream>

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