#include <iostream>

void swap(std::string& str, int i, int j)
{
	const auto temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}
/*
 * "One slow runner and the other fast runner" are usually the type of problems that involves
 * two pointers. There is another variation to that, where one pointer starts from the beginning while
 * the other pointer starts from the end. From reverse.cpp, this could be solved as well using the
 * two-pointer technique. 
 */
void reverse(std::string &str)
{
	unsigned int j = str.length() - 1, i = 0; 
	while(i < j)
	{
		swap(str, i, j);
		i++;
		j--; 
	}
}

int main(int argc, char** argv)
{
	
}