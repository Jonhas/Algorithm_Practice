#include <iostream>
#include "vector.h"

template<typename T>
void print(const Vector<T>& vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		std::cout << vector[i] << '\n'; 
	}
	std::cout << "----------------------------------\n"; 
}

int main() {
	Vector<std::string> vector; 
	vector.PushBack("Yo"); 
	vector.PushBack("Does this work?"); 
	print(vector); 
}