#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nbrs;

	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(666);
	nbrs.push_back(30);

	try
	{
		std::cout << "--1st test--" << std::endl;
		std::vector<int>::iterator it = easyfind(nbrs, 666);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}
	try
	{
		std::cout << "--2nd test--" << std::endl;
		std::vector<int>::iterator it = easyfind(nbrs, 300);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found" << std::endl;
	}
}