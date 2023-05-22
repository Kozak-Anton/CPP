#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Queue.h"

using namespace std;

//types supported by queue editor
enum type_used { type_int, type_char, type_string };

//QueueEditor: class holds Queue objects of several types and supports type independent operations
class QueueEditor {
	Queue<int> queue_int;														//Queue of ints
	Queue<char> queue_char;														//Queue of chars
	Queue<std::string> queue_string;											//Queue of strings
	int current_type;															//type in use
	template <typename T> void fill_queue(istream&, Queue<T>&);					//fill selected queue with items from input
	template <typename T> void push_queue(istream&, Queue<T>&);					//add item to selected queue from input
	template <typename T> void output_queue(ostream&, Queue<T>&);				//print selected queue to output
public:
	QueueEditor() : current_type(-1) {};
	void make(istream&);														//make and set queue of selected type
	void push(istream&);														//add item to current queue from input
	void pop(ostream&);															//take item from current queue from input
	void clear();																//empty current queue
	void print(ostream&);														//print current queue to output
};

template<typename T>
void QueueEditor::fill_queue(istream& item_list, Queue<T>& obj){
	T item;
	while (item_list >> item) obj.push(item);
}

template<typename T>
void QueueEditor::push_queue(istream& item_list, Queue<T>& obj){
	T item;
	item_list >> item;
	obj.push(item);
}

template<typename T>
void QueueEditor::output_queue(ostream& output, Queue<T>& obj){
	if (obj.empty()) return;
	auto it = obj.begin();
	for (; it != obj.end(); ++it) output << *it << " ";
	output << *it << endl;
}

void QueueEditor::make(std::istream& input){
	clear();

	string line, set_type;
	getline(input, line);
	istringstream item_list(line);

	item_list >> set_type;
	if (set_type == "int") current_type = type_int;
	else if (set_type == "char") current_type = type_char;
	else if (set_type == "string") current_type = type_string;
	else {
		cout << "Incorrect input" << endl;
		return;
	}

	switch (current_type) {
		case type_int:		fill_queue(item_list, queue_int); break;
		case type_char:		fill_queue(item_list, queue_char); break;
		case type_string:	fill_queue(item_list, queue_string); break;
	}
}

void QueueEditor::push(istream& input){

	switch (current_type) {
		case type_int:		push_queue(input, queue_int); break;
		case type_char:		push_queue(input, queue_char); break;
		case type_string:	push_queue(input, queue_string); break;
		default:			break;
	}
}

void QueueEditor::pop(ostream& output){
	try {
		switch (current_type) {
			case type_int:		output << "Item taken: " << queue_int.pop() << endl; break;
			case type_char:		output << "Item taken: " << queue_char.pop() << endl; break;
			case type_string:	output << "Item taken: " << queue_string.pop() << endl; break;
			default:			output << "Pop on empty Queue" << endl; break;
		}
	}
	catch (logic_error err) {
		output << err.what();
	}
}

void QueueEditor::clear() {
	switch (current_type) {
		case type_int:		queue_int.clear(); break;
		case type_char:		queue_char.clear(); break;
		case type_string:	queue_string.clear(); break;
		default: break;
	}
	current_type = -1;
}

void QueueEditor::print(ostream& output) {
	switch (current_type) {
		case type_int:		output_queue(output, queue_int); break;
		case type_char:		output_queue(output, queue_char); break;
		case type_string:	output_queue(output, queue_string); break;
		default:			output << "Queue is empty" << endl; break;
	}
}