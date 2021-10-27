#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

template <typename T>
class Stack: public LinkedList<T> {
private:
	unsigned int static _count;
public:
	Stack(const T data = 0) : LinkedList<T>(data) {
		_count++;
	}

	~Stack() {
		_count--;
	}

	inline void push(const T data) {
		LinkedList<T>::prepend(data);
		LinkedList<T>::_len++;
	}

	inline T pop() {
		T result = LinkedList<T>::head->_data;
		LinkedList<T>::remove();
		LinkedList<T>::_len--;
		return result;
	}

	inline T peek() const {
		return LinkedList<T>::head->_data;
	}

	inline unsigned int getLength() const {
		return LinkedList<T>::_len;
	}
};

template <typename T>
unsigned int Stack<T>::_count = 0;

#endif