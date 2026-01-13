#include "Zombie.hpp"

int main()
{
	Zombie *zomb = newZombie("Warden Zombie Of Heap");
	zomb->announce();
	delete zomb;

	randomChump("Warden Zombie Of Stack");

	return (0);
}
