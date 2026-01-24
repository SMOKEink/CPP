#include "ScavTrap.hpp"

int main()
{
	std::cout << "----- Construction -----" << std::endl;
	ScavTrap a("Samu");

	std::cout << "\n----- Actions -----" << std::endl;
	a.attack("Enemy");
	a.takeDamage(40);
	a.beRepaired(20);

	std::cout << "\n----- Special Ability -----" << std::endl;
	a.guardGate();

	std::cout << "\n----- Destruction -----" << std::endl;
	return 0;
}
