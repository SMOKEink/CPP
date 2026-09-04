#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

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
		for(; first != end; ++first)
			addNumber(*first);
	}
};

#endif