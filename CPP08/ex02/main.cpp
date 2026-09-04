#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(666);
	std::cout << "----------top---------\n" << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "---------size---------\n" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(50);
	mstack.push(737);
	mstack.push(1337);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();
	++it;
	--it;
	std::cout << "----stack with iterator ----" << std::endl;
	for (; it != end; ++it)
		std::cout << *it << std::endl;
	std::stack<int> s(mstack);
}