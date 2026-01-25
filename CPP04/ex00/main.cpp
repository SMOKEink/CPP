#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "-------------------------------" << std::endl;
    Animal* animal = new Animal();
    Animal* dogAnimal = new Dog();
    Animal* catAnimal = new Cat();

    std::cout << "dogAnimal type : " << dogAnimal->getType() << std::endl;
    std::cout << "catAnimal type : " << catAnimal->getType() << std::endl;

    animal->makeSound();
    dogAnimal->makeSound();
    catAnimal->makeSound();

    delete (animal);
    delete (dogAnimal);
    delete (catAnimal);

    std::cout << "\n-------------------------------" << std::endl;
    WrongAnimal* wrongCatAnimal = new WrongCat();

    std::cout << "wrongCatAnimal type : " << wrongCatAnimal->getType() << std::endl;
    wrongCatAnimal->makeSound();

    delete (wrongCatAnimal);

    return (0);
}
