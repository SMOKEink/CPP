#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon weapon1 = Weapon("BERETTA MODEL 93R");
	HumanA bob("Bob", weapon1);
	bob.attack();
	weapon1.setType("Kalashnikov AK-47");
	bob.attack();

	Weapon weapon2 = Weapon("Manhattan NAVY");
	HumanB Abdo("Abdo");
	Abdo.attack();
	Abdo.SetWeaponB(weapon2);
	Abdo.attack();
	weapon2.setType("BAZOGA");
	Abdo.attack();
	return (0);
}
