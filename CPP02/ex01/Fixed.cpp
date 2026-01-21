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

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNb = intValue * (1 << fractionalBits);
};

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointNb = roundf(floatValue * (1 << fractionalBits));
};

int Fixed::toInt(void) const
{
	return (fixedPointNb / (1 << fractionalBits));
};

float Fixed::toFloat(void) const
{
	return ((float)fixedPointNb / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
};