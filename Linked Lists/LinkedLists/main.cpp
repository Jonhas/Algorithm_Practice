#include <iostream>
#include "LinkedList.h"
int main()
{
	auto* head = new Node<int>(3, nullptr, nullptr);
	auto* tail = new Node<int>(5, nullptr, head);
	head->next = tail; 
	auto* linked = new list::LinkedList<int>(head, tail);
	if (!linked) return -1;
	linked->push_front(10); 
	linked->print_list();
	return 0; 
}