#include "lib.h"

TIntNumber* write_array(int& num, int base) {
	TIntNumber* temp = nullptr;

	cout << "Input number of elements: ";
	do {
		cin >> num;
	} while (num < 0);

	if (base == 2) {
		temp = new TIntNumber2[num];
		for (int i = 0; i < num; i++) {
			temp[i].set_number();
		}
	}
	else if (base == 8) {
		temp = new TIntNumber8[num];
		 for (int i = 0; i < num; i++) {
			 temp[i].set_number();
		}
	}

	return temp;
}

void read_array(TIntNumber* array, int num) {
	for (int i = 0; i < num; i++) {
		array[i].read_number();
	}
}

void increment_array(TIntNumber* array, int num) {
	for (int i = 0; i < num; i++) {
		array[i]++;
	}
}

void decrement_array(TIntNumber* array, int num) {
	for (int i = 0; i < num; i++) {
		array[i]--;
	}
}

int find_min(TIntNumber* array1, int num1, TIntNumber* array2, int num2) {
	int min = 0;
	if (num1 > 0) {
		min = array1[0].get_number();
		for (int i = 1; i < num1; i++) {
			if (array1[i].get_number() < min)
				min = array1[i].get_number();
		}
	}
	if (num2 > 0) {
		if (min==0 && num1==0)
			min = array2[0].get_number();
		for (int i = 1; i < num2; i++) {
			if (array2[i].get_number() < min)
				min = array2[i].get_number();
		}
	}
	return min;
}