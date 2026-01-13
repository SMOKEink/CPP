#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;	
public:
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	const std::string &getType() const;
};







#endif