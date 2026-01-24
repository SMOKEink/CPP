#include "ClapTrap.hpp"

int main()
{
	std::cout << "----- Creating ClapTraps -----" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	std::cout << "\n----- Basic actions -----" << std::endl;
	a.attack("Beta");
	b.takeDamage(0);
	b.beRepaired(5);

	std::cout << "\n----- Energy depletion -----" << std::endl;
	for (int i = 0; i < 11; i++)
		a.attack("BRAHIM");

	std::cout << "\n----- Damage until death -----" << std::endl;
	b.takeDamage(3);
	b.takeDamage(20);
	b.takeDamage(20);

	std::cout << "\n----- Actions after death -----" << std::endl;
	b.attack("Ghost");
	b.beRepaired(10);

	std::cout << "\n----- Copy & assignment tests -----" << std::endl;
	ClapTrap c(a);
	ClapTrap d;
	d = a;

	std::cout << "\n----- End of main -----" << std::endl;
	return 0;
}
