#pragma once
#include "TIntNumber.h"
#include <string>
#include <iostream>

class TIntNumber2 :public TIntNumber {
public:
	TIntNumber2();												//new base
	void virtual set_number();									//sets number values(base is always 2)
};