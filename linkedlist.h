#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>

template <typename T>
class Node {
public:
	T _data;
	Node<T>* _next;
	static unsigned int _count;

	Node(const T data = 0) : _data(data) {
		_next = nullptr;
		Node<T>::_count++;
	}

	~Node() {
		Node<T>::_count--;
	}
};

template <typename T>
unsigned int Node<T>::_count = 0;

template <typename T>
class LinkedList {
private:
	static unsigned int _count;
protected:
	unsigned int _len;
	bool _cyclic;
public:
	Node<T>* head;

	LinkedList(const T data = 0) {
		head = new Node<T>(data);
		head->_next = nullptr;
		_len = 1;
		_cyclic = false;
		_count++;
	}

	~LinkedList() {
		Node<T>* current = head;
		Node<T>* next = head;

		if (_cyclic) {
			removeCycle();
			_cyclic = false;
		}

		while (current != nullptr) {
			next = current->_next;
			delete current;
			current = next;
		}

		_count--;
	}

	void printList() const {
		Node<T>* current = head;
		for (unsigned int i = 0; i < _len && current != nullptr; i++) {
			std::cout << i << ": " << current->_data << ", ";
			current = current->_next;
		}
		std::cout << std::endl;
	}

	void prepend(const T data) {
		Node<T>* newNode = new Node<T>(data);
		newNode->_next = head;
		head = newNode;
		_len++;
	}

	void append(const T data) {
		Node<T>* current = head;
		Node<T>* newNode = new Node<T>(data);

		while (current->_next != nullptr) {
			current = current->_next;
		}

		current->_next = newNode;
		_len++;
	}

	void prependAt(const unsigned int index, const T data) {
		assert(index <= _len);

		Node<T>* current = head;
		Node<T>* newNode = new Node<T>(data);

		for (unsigned int i = 0; i < (index-1) && current->_next != nullptr; i++) {
			current = current->_next;
		}

		newNode->_next = current->_next;
		current->_next = newNode;

		_len++;
	}

	void appendAt(const unsigned int index, const T data) {
		assert(index < _len);

		Node<T>* current = head;
		Node<T>* newNode = new Node<T>(data);

		for (unsigned int i = 0; i < index && current != nullptr; i++) {
			current = current->_next;
		}
		
		newNode->_next = current->_next;
		current->_next = newNode;

		_len++;
	}

	void deleteNode(const unsigned int index) {
		assert(index < _len);

		if (index == 0) {
			remove();
			return;
		}

		Node<T>* current = head;
		Node<T>* prev = nullptr;

		for (unsigned int i = 0; i < index && current!= nullptr; i++) {
			prev = current;
			current = current->_next;
		}

		if (prev != nullptr && current != nullptr) {
			prev->_next = current->_next;
		}

		delete current;

		_len--;
	}

	void remove() {
		if (head == nullptr) return;
		if (_cyclic) removeCycle();

		Node<T>* save = head->_next;

		delete head;
		head = save;
	}

	Node<T>* getTail() const {
		Node<T>* current = head;

		while (current->_next != nullptr) {
			current = current->_next;
		}

		return current;
	}

	Node<T>* getNodeAt(const unsigned int index) const {
		Node<T>* current = head;

		for (unsigned int i = 0; i < index && current != nullptr; i++) {
			current = current->_next;
		}

		return current;
	}

	void makeCycle() {
		Node<T>* current = head;

		while (current->_next != nullptr) {
			current = current->_next;
		}

		current->_next = head;
		_cyclic = true;
	}

	void removeCycle() {
		if (_cyclic) {
			Node<T>* current = head;
			Node<T>* save = head;

			while (current != nullptr) {
				current = current->_next;
				if (current->_next == save) {
					current->_next = nullptr;
					break;
				}
			}
		}
	}

	bool hasCycle() const {
		Node<T>* current = head;
		Node<T>* save = head;

		while (current != nullptr) {
			current = current->_next;
			if (save == current) {
				_cyclic = true;
				return true;
			}
		}

		_cyclic = false;
		return false;
	}

	LinkedList<T> copyList() const {
		LinkedList<T> newList();
		Node<T>* current = head;

		if (_cyclic) {
			Node<T>* save = head;

			while (current != nullptr) {
				newList.append(current->_data);
				current = current->_next;
				if (current == save) break;
			}
		}
		else {
			while (current != nullptr) {

			}
		}
	}
};

template <typename T>
unsigned int LinkedList<T>::_count = 0;

#endif