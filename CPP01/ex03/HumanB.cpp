#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with a Slap (Unarmed)" << std::endl;
}

void HumanB::SetWeaponB(Weapon& weapon)
{
	this->weapon = &weapon;
}