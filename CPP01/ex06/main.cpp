#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Enter Just One Argument" << std::endl;
		return (1);
	}
	Harl harlFilter;

	harlFilter.complain(av[1]);
	return 0;
}