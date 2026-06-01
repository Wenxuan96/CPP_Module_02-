#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int val;
		static const int fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);//copy constructor
		Fixed& operator=(const Fixed& other);//copy assignment operator
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};