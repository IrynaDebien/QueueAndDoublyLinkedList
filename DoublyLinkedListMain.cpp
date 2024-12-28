#include "DoublyLinkedList.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);

	cout << "Queue: ";
	queue.display();

	queue.dequeue();
	cout << "After removing the element from the front: ";
	queue.display();

	queue.swapHeadTail(); // Swap head and tail
	cout << "After swapping head and tail: ";
	queue.display();

	return 0;
}
