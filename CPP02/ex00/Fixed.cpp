#include "Fixed.hpp"

int const Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	fixedPointNb = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNb = other.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNb = other.getRawBits();
	return (*this);
};

void Fixed::setRawBits(int const raw)
{
	fixedPointNb = raw;
};

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNb);
};