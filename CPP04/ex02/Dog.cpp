#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete (brain);
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete (brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "* Haw Haw *" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}
