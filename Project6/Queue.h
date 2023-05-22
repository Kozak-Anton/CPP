#pragma once
#include <stdexcept>

//Queue: class represents a queue build of an array
template <typename T>
class Queue {
	int size;												//size of a queue
	int head;												//position of first member of a queue
	int tail;												//position of 1 past final member of a queue
	T* data;												//pointer to array of members
public:	
	class Iterator;											//Iterator: class represents an iterator for a Queue object
	Queue(int new_size=20);
	~Queue();
	int get_size() { return size; }							//returns size of queue
	bool empty() { return head == tail; }					//check whether queue is empty
	Iterator begin() { return Iterator(this, head); }		//returns iterator pointing to first member of queue
	Iterator end() { return Iterator(this, tail-1); }		//returns iterator pointing to final member of queue
	void clear();											//empties the queue
	void push(const T&);									//adds member to the queue
	T pop();												//takes a memeber from the queue
};

//Iterator: class represents an iterator for a Queue object
template <typename T>
class Queue<T>::Iterator {
	friend class Queue;
	Queue* obj;												//pointer to which object iterator refers to
	T* value;												//pointer to queue member
	Iterator(Queue*, int);									//binds queue object to iterator and sets starting position
public:
	Iterator() : obj(nullptr), value(nullptr) {};
	T& operator*() { return *value; }						
	T* operator&() { return value; }
	friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.value == rhs.value; }
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return lhs.value != rhs.value; }
	Iterator& operator++();
	Iterator& operator++(int);
	Iterator& operator--();
	Iterator& operator--(int);
	
};

template<typename T>
Queue<T>::Queue(int new_size){
	if (new_size < 1) {
		head = tail = size = 0;
		data = nullptr;
	}
	else {
		size = new_size;
		head = tail = 0;
		data = new T[size];
	}
}

template<typename T>
Queue<T>::~Queue(){
	delete[] data;
}

template<typename T>
void Queue<T>::clear(){
	delete[] data;
	data = nullptr;
	size = tail = 0;
}

template<typename T>
void Queue<T>::push(const T& mem){
	if (size == 0) {
		data = new T[20];
	}
	else if (tail==size) {
		T* temp = new T[size * 2];
		for (int i = 0; i < size; ++i) temp[i] = data[i];
		delete[] data;
		data = temp;
	}
	data[tail++] = mem;
}

template<typename T>
T Queue<T>::pop(){
	if (this->empty()) throw std::logic_error("Pop on empty Queue\n");
	T temp = data[head];
	--tail;
	for (int i = head; i < tail; ++i) data[i] = data[i + 1];
	return temp;
}

template<typename T>
Queue<T>::Iterator::Iterator(Queue<T>* new_obj, int pos) {
	obj = new_obj;
	value = new_obj->data+pos;
}

template<typename T>
auto Queue<T>::Iterator::operator++() -> Iterator& {
	if (value == nullptr) return *this;
	if (value == obj->data + obj->tail - 1) value = obj->data;
	else ++value;
	return *this;
}

template<typename T>
auto Queue<T>::Iterator::operator++(int) -> Iterator& {
	Iterator temp = *this;
	this->operator++();
	return temp;
}

template<typename T>
auto Queue<T>::Iterator::operator--() -> Iterator& {
	if (value == nullptr) return *this;
	if (value == obj->data) value = obj->data + obj->tail - 1;
	else --value;
	return *this;
}

template<typename T>
auto Queue<T>::Iterator::operator--(int) -> Iterator& {
	Iterator temp = *this;
	this->operator--();
	return temp;
}
