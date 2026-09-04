#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span(unsigned int N) : maxSize(N)
{}

Span::Span(const Span& other) : maxSize(other.maxSize), nbrs(other.nbrs)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		nbrs = other.nbrs;
	}
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int nb)
{
	if (nbrs.size() >= maxSize)
		throw std::exception();
	nbrs.push_back(nb);
}

unsigned int Span::shortestSpan()
{
	if (nbrs.size() < 2)
		throw std::exception();
	std::vector<int> tmp = nbrs;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator it = tmp.begin();
	std::vector<int>::iterator next = tmp.begin() + 1;
	unsigned int shortest = *next - *it;
	++it;
	++next;
	for (; next != tmp.end(); ++next)
	{
		unsigned int dist = *next - *it;
		if (dist < shortest)
			shortest = dist;
		++it;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if (nbrs.size() < 2)
		throw std::exception();
	return (*std::max_element(nbrs.begin(), nbrs.end()) -
			*std::min_element(nbrs.begin(), nbrs.end()));
}
