#include <iostream>
#include "vector.h"

struct Vector3 {
	float x = 0.0f, y = 0.0f, z = 0.0f; 
	Vector3() {}
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) {}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z) {}
	Vector3(const Vector3& other) 
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "copy\n"; 
	}

	Vector3(Vector3&& other) noexcept 
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "copy\n";
	}
	~Vector3() {
		std::cout << "Destroy\n"; 
	}

	Vector3& operator=(const Vector3& other) {
		std::cout << "copy\n"; 
		x = other.x; 
		y = other.y; 
		z = other.z; 
		return *this; 
	}
	Vector3& operator=(Vector3&& other) {
		std::cout << "move\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}	
};
template<typename T>
void print(const Vector<T>& vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		std::cout << vector[i] << '\n';
	}
	std::cout << "----------------------------------\n";
}

template<>
void print(const Vector<Vector3>& vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		std::cout << vector[i].x << vector[i].y << vector[i].z << '\n';
	}
	std::cout << "----------------------------------\n";
}
int main() {
	Vector<std::string> Stringvector;
	Stringvector.PushBack("Yo");
	Stringvector.PushBack("Does this work?");
	Stringvector.PushBack("Does this work?");
	Stringvector.PushBack("Does this work?");
	print(Stringvector);
	std::cout << "-------------------------------\n";

	Vector<Vector3> vector; 
	vector.EmplaceBack(1.0f); 
	vector.EmplaceBack(2,3,4);
	vector.EmplaceBack(2, 32, 5);
	vector.PopBack(); 
	vector.EmplaceBack();
	vector.PopBack();
	vector.EmplaceBack(1, 3, 53);
	print(vector); 
	vector.Clear(); 
	return 0; 

}