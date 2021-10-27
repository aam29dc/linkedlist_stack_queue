#include <iostream>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

int main() {
	int data = 0;
	Queue<int> q(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	data = q.dequeue();

	q.printList();

	Stack<int> s(1);
	s.push(2);
	s.push(3);
	data = s.pop();

	s.printList();

	LinkedList<int> ll(0);
	ll.append(11);
	ll.prepend(22);
	ll.printList();

	return 0;
}