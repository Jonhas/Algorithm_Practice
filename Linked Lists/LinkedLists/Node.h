#pragma once
#include <iostream>
template<class T>
class Node {
public:
	Node(const T& data, Node<T>* next, Node<T>* prev)
		: data(data), next(next), prev(prev) {}
	explicit Node(const T& data)
		: data(data), next(nullptr), prev(nullptr) 
	{}
	~Node()
	{
		next = nullptr;
		prev = nullptr;
		::operator delete(next);
		::operator delete(prev);
		std::cout << "deallocation of Nodes" << '\n'; 
	}
	T data; 
	Node<T>* next;
	Node<T>* prev;
};