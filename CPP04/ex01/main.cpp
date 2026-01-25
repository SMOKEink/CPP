#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "---- Animal array test ----" << std::endl;
	const Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
		delete (animals[i]);

	std::cout << "\n---- Deep copy test ----" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I want food");

	Dog copy = original;
	copy.getBrain()->setIdea(0, "I want sleep");

	std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;

	std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;

	return (0);
}
