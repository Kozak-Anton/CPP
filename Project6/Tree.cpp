#include "Tree.h"

void Tree::input_tree() {
	float val;
	Node* current = root;
	
	cout << "Input number: ";
	cin >> val;
	current-> num = val;

	while (cin >> val) {
		if (val >= current->num) {
			current->right = new Node(val);
			current = current->right;
		}
		else {
			current->left = new Node(val);
			current = current->left;
		}
	}
}