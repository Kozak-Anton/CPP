#pragma once
#include "TIntNumber.h"
#include <string>
#include <iostream>

class TIntNumber8 :public TIntNumber {
public:
	TIntNumber8();                                              //new base
	void virtual set_number();									//sets number values(base is always 8)
};