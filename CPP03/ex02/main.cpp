#include "FragTrap.hpp"

int main()
{
    FragTrap a("Fraggy");

    a.attack("enemy");
    a.takeDamage(40);
    a.beRepaired(20);
    a.highFivesGuys();

    return (0);
}

