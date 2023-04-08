#pragma once

#include "Ring.h"
#include<iostream>
#include<string>
#include <ctype.h>

using namespace std;

enum arguments {end_prog = 0, error, find_max, read, prefix, postfix, multiply};  //list of commands

void read_ring(Ring);                                                             //outputs ring  data
arguments read_command(int& num, int& multiplier);                                //reads command from input
void find_max_ring(Ring, Ring, Ring);                                             //finds ring with max width