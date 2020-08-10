#ifndef VECTOR_H
#define VECTOR_H
#pragma once 

template<typename T>
class Vector {
public:
	Vector() 
	{
		//allocate two elements for every initialization of a vector 
		ReAlloc(2); 
	}

	void PushBack(const T& value)
	{
		if (size >= capacity) ReAlloc(capacity + capacity / 2); 
		data[size++] = value; 
	}

	const T& operator[](size_t index) const { return data[index];  }
	T& operator[](size_t index) { return data[index]; }


	size_t Size() const { return size;  }
private:
	void ReAlloc(size_t newCapacity) 
	{
		//1. Allocate a new block of memory 
		//2. move old elements into new block 
		//3. delete
		T* newBlock = new T[newCapacity];
		//if (newCapacity < size) size = newCapacity; 
		checkdeAllocSize(newCapacity, size); 
		for (std::size_t i = 0; i < size; i++)
			newBlock[i] = data[i];
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}
	void checkdeAllocSize(size_t newCapacity, size_t &size) 
	{
		if (newCapacity < size) size = newCapacity; 
	}
private:
	T* data = nullptr; 
	size_t size = 0; //How much elements currently within the vector
	size_t capacity = 0; //how much elements can be stored without having to reallocate the vector.  
};

#endif // !VECTOR_H

