#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
		delete animals[i];
	}

	return (0);
}
