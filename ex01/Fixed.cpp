#include "Fixed.hpp"

Fixed::Fixed():val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	val = n << fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl; //bitshifting sign only works on int not float
	val = roundf(n * (1 << fractionalBits)); //thats why we cannot write n << fractionalBits directly when n is float
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	val = other.val;
}

Fixed& Fixed:: operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->val = other.val;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed:: toFloat(void) const
{
	return (float)val/(1 << fractionalBits);
}

int Fixed:: toInt(void) const
{
	return roundf(toFloat());
	//return val >> fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}