#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array() : data(NULL), _size(0)
{} 

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* newData = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			newData[i] = other.data[i];
		delete [] data;
		data = newData;
		_size = other._size;
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete [] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif