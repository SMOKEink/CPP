#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <exception>

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;
    Span sp(9);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;

    std::cout << "===== ITERATOR TEST =====" << std::endl;
    std::list<int> numbers;
    numbers.push_back(50);
    numbers.push_back(0);
    numbers.push_back(49);
    numbers.push_back(1337);
    sp.addNumber(numbers.begin(), numbers.end());
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;

    std::cout << "===== CAPACITY TEST =====" << std::endl;
    try
    {
        sp.addNumber(666);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: Span is full!" << std::endl;
    }

    std::cout << "===== 10,000 NUMBERS TEST =====" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(i);
    std::cout << "shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longest : " << bigSpan.longestSpan() << std::endl;

    std::cout << "===== 10,000 ITERATOR INSERTION =====" << std::endl;
    std::vector<int> bigNumbers;
    for (int i = 0; i < 10000; ++i)
        bigNumbers.push_back(i * 2);

    Span rangeSpan(10000);
    rangeSpan.addNumber(bigNumbers.begin(), bigNumbers.end());
    std::cout << "shortest: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "longest : " << rangeSpan.longestSpan() << std::endl;

    std::cout << "===== COPY CONSTRUCTOR TEST =====" << std::endl;
    Span copySpan(bigSpan);
    std::cout << "shortest: " << copySpan.shortestSpan() << std::endl;
    std::cout << "longest : " << copySpan.longestSpan() << std::endl;

    std::cout << "===== ASSIGNMENT TEST =====" << std::endl;
    Span assignedSpan(5);
    assignedSpan = bigSpan;
    std::cout << "shortest: " << assignedSpan.shortestSpan() << std::endl;
    std::cout << "longest : " << assignedSpan.longestSpan() << std::endl;
}