#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

template <typename T>
class Queue: public LinkedList<T> {
private:
	unsigned int static _count;
public:
	Queue(const T data): LinkedList<T>(data) {
		_count++;
	}
	~Queue() {
		_count--;
	}

	inline void enqueue(const T data) {
		LinkedList<T>::append(data);
	}

	inline T dequeue() {
		T result = LinkedList<T>::head->_data;
		LinkedList<T>::remove();
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
unsigned int Queue<T>::_count = 0;

#endif