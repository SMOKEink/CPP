#include "iter.hpp"

#include <iostream>

class Printer
{
public:
    void operator()(int x)
    {
        std::cout << x << std::endl;
    }
};

template <typename T>
void plus(T value)
{
	value++;
}

int main()
{
	Printer p;
	int arr[3] = {11, 12, 13};

	iter(arr, static_cast<size_t>(3), plus<int>);
	iter(arr, static_cast<size_t>(3), p);
}