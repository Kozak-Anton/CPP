#pragma once

#include "TIntNumber.h"
#include "TIntNumber2.h"
#include "TIntNumber8.h"

TIntNumber* write_array(int&, int );                           //inputs array of numbers in set base
void read_array(TIntNumber*, int);                             //read array of numbers
void increment_array(TIntNumber*, int);                        //increments all numbers in array
void decrement_array(TIntNumber*, int);                        //decrements all numbers in array
int find_min(TIntNumber*, int, TIntNumber*, int);              //finds min number amoung 2 arrays