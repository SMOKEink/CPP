#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename T, typename F>
void iter(T* array, const size_t length, F fnct)
{
	for (size_t i = 0; i < length; i++)
		fnct(array[i]);
}

#endif