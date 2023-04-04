#pragma once

#include "Ring.h"
#include<iostream>
#include<string>
#include <ctype.h>

using namespace std;

enum arguments {end_prog = 0, error, find_max, read, prefix, postfix, multiply};

void read_ring(Ring);
arguments read_command(int& num, int& multiplier);
void find_max_ring(Ring, Ring, Ring);