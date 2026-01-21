#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = intValue * (1 << fractionalBits);
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(floatValue * (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (rawBits / (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)rawBits / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& cout, const Fixed& fixed)
{
	cout << fixed.toFloat();
	return (cout);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (rawBits > other.rawBits);
}
bool Fixed::operator<(const Fixed &other) const
{
	return (rawBits < other.rawBits);
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (rawBits >= other.rawBits);
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (rawBits <= other.rawBits);
}
bool Fixed::operator==(const Fixed &other) const
{
	return (rawBits == other.rawBits);
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (rawBits != other.rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed sum;
	sum.setRawBits(this->rawBits + other.rawBits);
	return (sum);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed diff;
	diff.setRawBits(this->rawBits - other.rawBits);
	return (diff);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed product;
	long res = (long)rawBits * (long)other.rawBits;
	product.setRawBits(res / (1 << fractionalBits));
	return (product);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed quotient;
	long res = ((long)rawBits << fractionalBits) / other.rawBits;
	quotient.setRawBits(res);
	return (quotient);
}