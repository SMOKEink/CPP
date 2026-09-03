#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "---------Empty array---------" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "---------Normal array---------" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "---------Modify elements---------" << std::endl;
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "---------Copy constructor---------" << std::endl;
    Array<int> b(a);
    b[0] = 999;
    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "b[0]: " << b[0] << std::endl;

    std::cout << "---------operator =---------" << std::endl;
    Array<int> c;
    c = a;
    c[1] = 888;
    std::cout << "a[1]: " << a[1] << std::endl;
    std::cout << "c[1]: " << c[1] << std::endl;

    std::cout << "---------Out of bounds---------" << std::endl;
    try
    {
        std::cout << a[100] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught!" << std::endl;
    }

    std::cout << "---------String array---------" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "cpp";
    words[2] = "07";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;
}