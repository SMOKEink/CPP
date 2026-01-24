#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Samu");

	std::cout << "\n--------------------------------------" << std::endl;
	a.attack("Enemy");
	a.takeDamage(40);
	a.beRepaired(20);

	std::cout << "\n--------------------------------------" << std::endl;
	a.guardGate();

	std::cout << "\n--------------------------------------" << std::endl;
	return (0);
}
