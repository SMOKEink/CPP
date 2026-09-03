#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
	value++;
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};

	std::cout << "-Before:" << std::endl;
	iter(numbers, 5, print<int>);
	iter(numbers, 5, increment<int>);

	std::cout << "-After:" << std::endl;
	iter(numbers, 5, print<int>);

	const int constNumbers[] = {10, 20, 30};

	std::cout << "-Const array:" << std::endl;
	iter(constNumbers, 3, print<int>);

	std::string words[] = {"hello", "world", "cpp"};

	std::cout << "-Strings:" << std::endl;
	iter(words, 3, print<std::string>);
}