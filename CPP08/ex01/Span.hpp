#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
private:
	unsigned int maxSize;
	std::vector<int> nbrs;
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int nb);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename iter>
	void addNumber(iter first, iter end)
	{
		std::vector<int> tmp;

		for (; first != end; ++first)
			tmp.push_back(*first);
		if (nbrs.size() + tmp.size() > maxSize)
			throw std::exception();
		nbrs.insert(nbrs.end(), tmp.begin(), tmp.end());
	}
};

#endif