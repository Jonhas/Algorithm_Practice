#pragma once
#include <iostream>
#include "Node.h"
namespace list {
	template<class T>
	class LinkedList {
	public:
		//Empty List
		explicit LinkedList() noexcept
			:size(0), head_(nullptr), tail_(nullptr) {}
		LinkedList(Node<T>* head, Node<T>* tail) noexcept 
			: size(2), head_(head), tail_(tail)
		{
			head_->next = tail_;
			head_->prev = nullptr;
			
			tail_->next = nullptr;
			tail_->prev = head_; 
		}

		~LinkedList();
		void clear();
		void assign(const unsigned int amount, const T& val);
		void push_front(T&& val);
		Node<T>* insert(const unsigned int position, const T&& val); 
		T& operator [](T const index);
		T const& operator [](T const index) const;
		constexpr void print_list() const; 
		constexpr bool is_empty() const;
		constexpr unsigned int Size() const;
	public:
		unsigned int size;
	private:
		Node<T>* head_ = nullptr;
		Node<T>* tail_ = nullptr;
	};

	/*
	 * De-constructor for the LinkedList class
	 */
	template <class T>
	LinkedList<T>::~LinkedList()
	{
		std::cout << "Linked List Destructor invoked" << '\n'; 
		clear();
	}

	/*
	 * Removes all elements from the list container(which are destroyed), and leaving the container with
	 * a size of 0.
	 */
	template <class T>
	void LinkedList<T>::clear()
	{
		if (head_)
		{
			Node<T>* head_temp = head_;
			Node<T>* temp = nullptr;
			while (head_temp)
			{
				temp = head_temp;
				temp->prev = nullptr;
				temp->next = nullptr;
				temp = nullptr; 
				head_temp = head_temp->next;
				::operator delete (temp);
			}
		}
		size = 0;
	}

	/*
	 * Assigns new contents to the list container, replacing its current contents, and
	 * modifying its size accordingly. Essentially, the new contents are n elements, each
	 * initialized to a copy of val. 
	 */
	template <class T>
	void LinkedList<T>::assign(const unsigned int amount, const T& val)
	{
		unsigned int count = 1; 
		if(head_)
		{
			Node<T>* head_temp = head_;
			while(count < amount)
			{
				head_temp = new Node<T>(val, nullptr, head_temp);
				head_temp = head_temp->next;
				count++;
			}
			tail_ = head_temp;
			size = count; 
		}
		else
		{
			head_ = new Node<T>(val, nullptr, nullptr);
			Node<T>* head_temp = head_;
			while(count < amount)
			{
				head_temp->next = new Node<T>(val, nullptr, head_temp);
				head_temp = head_temp->next;
				count++; 
			}
			tail_ = head_temp; 
			size = count; 
		}
	}

	template <class T>
	void LinkedList<T>::push_front(T&& val)
	{
		if(is_empty())
		{
			head_ = new Node<T>(std::move(val), nullptr, nullptr);
			tail_ = head_; 
		}
		else
		{
			head_->prev = new Node<T>(std::move(val), head_, nullptr);
			head_ = head_->prev; 
		}
		size++; 
	}

	/*
	 * The container is extended by inserting new elements before the element at the specified position. 
	 */
	template <class T>
	Node<T>* LinkedList<T>::insert(const unsigned position, const T&& val)
	{
		if(!head_)
		{
			head_ = new Node<T>(std::move(val), nullptr, nullptr);
			tail_=head_;
			size++; 
			return head_; 
		}
		if(position == 0)
		{
			push_front(val); 
		}
		if(position >= size)
		{
			std::cout << "Position is out of bounds in the Linked List" << '\n';
			return nullptr;
		}
		unsigned int index = 0;
		Node<T>* head_temp = head_;
		Node<T>* prev = nullptr; 
		Node<T>* temp = new Node<T>(std::move(val)); 
		while(head_temp)
		{
			if(index==position)
			{
				prev->next = temp;
				head_temp->next->prev = temp; 
				temp->prev = prev;
				temp->next = head_temp->next; 
				return temp; 
			}
			prev = head_temp; 
			head_temp = head_temp->next; 
			index++; 
		}
		std::cout << "Could not allocate new node into the linked list" << '\n'; 
		return nullptr;
	}
	
	/*
	 * Linear search for finding some value within the linked list. 
	 */
	template <class T>
	T& LinkedList<T>::operator[](T const index)
	{
		unsigned int ind = 0;
		Node<T>* head_temp = head_;
		while(head_temp)
		{
			if (ind == index) return head_temp->data;
			head_temp = head_temp->next;
			ind++; 
		}
		std::cout << "Out of Bound, index does not exist in linked list" << '\n';
		return -1; 
	}
	template <class T>
	constexpr void LinkedList<T>::print_list() const
	{
		Node<T>* temp = head_;
		unsigned int pos = 0; 
		while(temp)
		{
			std::cout << "Node value at position " << pos << " with value:" << temp->data << " \n";
			temp = temp->next;
			pos++; 
		}
	}

	/*
	 * Linear search for finding some value within the linked list.
	 */
	template <class T>
	T const& LinkedList<T>::operator[](T const index) const
	{
		unsigned int ind = 0;
		Node<T>* head_temp = head_;
		while (head_temp)
		{
			if (ind == index) return head_temp->data;
			head_temp = head_temp->next;
			ind++;
		}
		std::cout << "Out of Bound, index does not exist in linked list" << '\n';
		return -1;
	}

	
	/*
	 * Returns whether the list container is empty(i.e whether its size is 0)
	 * The function does not modify the container in any way. To clear the contents of
	 * the linked list, see LinkedList<T>::clear. 
	 */
	template <class T>
	constexpr bool LinkedList<T>::is_empty() const
	{
		return size == 0; 
	}

	/*
	 * Returns the number of elements in the list container
	 */
	template <class T>
	constexpr unsigned LinkedList<T>::Size() const 
	{
		return size; 
	}

}
