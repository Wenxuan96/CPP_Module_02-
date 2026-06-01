#include "Fixed.hpp"

Fixed::Fixed():val(0){}

Fixed::Fixed(const int n)
{
	val = n << fractionalBits;
}

int Fixed:: toInt() const
{
	return val >> fractionalBits;
}

Fixed::Fixed(const float f)
{
	val = roundf(f * (1 << fractionalBits)); 
}

float Fixed:: toFloat() const
{
	return (float)val/(1 << fractionalBits);
}

Fixed::Fixed(const Fixed& other)
{
	val = other.val;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->val = other.val;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const
{
	return val > other.val;
}

bool Fixed::operator<(const Fixed& other) const
{
	return val < other.val;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return val >= other.val;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return val <= other.val;
}

bool Fixed::operator==(const Fixed& other) const
{
	return val == other.val;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return val != other.val;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed newVal;
    newVal.val = this->val + other.val;
    return newVal;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed newVal;
    newVal.val = this->val - other.val;
    return newVal;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed newVal;
    newVal.val = (this->val * other.val) >> fractionalBits;
    return newVal;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed newVal;
    newVal.val = (this->val << fractionalBits) / other.val;
    return newVal;
}

Fixed& Fixed::operator++()
{
	this->val++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->val--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->val++;
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->val--;
	return old;
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}