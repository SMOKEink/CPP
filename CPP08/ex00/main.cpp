#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> nbrs;
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(666);
	nbrs.push_back(30);
	try
	{
		std::cout << "--vector 1st test--" << std::endl;
		std::vector<int>::iterator it = easyfind(nbrs, 666);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}
	try
	{
		std::cout << "--vector 2nd test--" << std::endl;
		std::vector<int>::iterator it = easyfind(nbrs, 300);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}

	std::list<int> numbers;
	numbers.push_back(500);
	numbers.push_back(42);
	numbers.push_back(11);
	numbers.push_back(25);
	try
	{
		std::cout << "--list 1st test--" << std::endl;
		std::list<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}
	try
	{
		std::cout << "--list 2nd test--" << std::endl;
		std::list<int>::iterator it = easyfind(numbers, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}
}