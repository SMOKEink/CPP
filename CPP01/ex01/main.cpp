#include "Zombie.hpp"

int main()
{
	int N = 2147483648;
	Zombie *horde = zombieHorde(N, "Zombie");
	if (!horde)
	{
		std::cout << "Error : N Out Of Range!" << std::endl;
		return (1);
	}
	for(int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}