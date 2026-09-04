#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <exception>

int main()
{
	std::cout << "------ main test ------" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest : " << sp.longestSpan() << std::endl;

	std::cout << "------- iterators -------" << std::endl;
	Span span(4);
	std::list<int> numbers;
	numbers.push_back(50);
	numbers.push_back(0);
	numbers.push_back(49);
	numbers.push_back(1337);
	span.addNumber(numbers.begin(), numbers.end());
	std::cout << "shortest: " << span.shortestSpan() << std::endl;
	std::cout << "longest : " << span.longestSpan() << std::endl;

	std::cout << "--------- limit ---------" << std::endl;
	try
	{
		span.addNumber(666);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: Span is full!" << std::endl;
	}

	std::cout << "-------- 10000 nb --------" << std::endl;
	Span bigSpan(10000);
	for (int i = 0; i < 10000; ++i)
		bigSpan.addNumber(i);
	std::cout << "shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "longest : " << bigSpan.longestSpan() << std::endl;

	std::cout << "----- 10000 by iter -----" << std::endl;
	Span rangeSpan(20000);
	std::vector<int> bigNumbers;
	for (int i = 0; i < 20000; ++i)
		bigNumbers.push_back(i);
	rangeSpan.addNumber(bigNumbers.begin(), bigNumbers.end());
	std::cout << "shortest: " << rangeSpan.shortestSpan() << std::endl;
	std::cout << "longest : " << rangeSpan.longestSpan() << std::endl;
}