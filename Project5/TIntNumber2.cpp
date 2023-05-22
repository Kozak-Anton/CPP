#include "TIntNumber2.h"

using namespace std;

TIntNumber2::TIntNumber2() {
	base = 2;													//new base
}
void TIntNumber2::set_number() {                                //sets number values(base is always 2)
	cout << "Input number in base 2: ";
	cin >> number_rep;
	convert_base_to_10();
}