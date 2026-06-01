#include "Fixed.hpp"

Fixed:: Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
}

Fixed:: Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	val = other.val;
}

Fixed& Fixed:: operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		val = other.getRawBits();
	return *this;
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return val;
}

void Fixed::setRawBits(int const raw)
{
	val = raw;
}