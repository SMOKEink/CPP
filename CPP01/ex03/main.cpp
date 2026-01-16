#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon weapon1 = Weapon("BERETTA MODEL 93R");
	HumanA Player1("Player1", weapon1);
	Player1.attack();
	weapon1.setType("Kalashnikov AK-47");
	Player1.attack();

	Weapon weapon2 = Weapon("Manhattan NAVY");
	HumanB Player2("Player2");
	Player2.attack();
	Player2.setWeapon(weapon2);
	Player2.attack();
	weapon2.setType("BAZOGA");
	Player2.attack();
	return (0);
}
