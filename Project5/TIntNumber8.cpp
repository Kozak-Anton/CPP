#include "TIntNumber8.h"

using namespace std;

TIntNumber8::TIntNumber8() {
	base = 8;													 //new base
}
void TIntNumber8::set_number() {                                //sets number values(base is always 8)
	cout << "Input number in base 8: ";
	cin >> number_rep;
	convert_base_to_10();
}