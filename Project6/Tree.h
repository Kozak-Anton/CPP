#pragma once
#include "lib.h"

struct Node
{
	float num;
	Node* left;
	Node* right;
	Node(float val) : num(val), left(nullptr), right(nullptr) {};
};

class Tree {
	Node* root;
public:
	Tree() : root(0) {};
	void input_tree();
};