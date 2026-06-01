#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int val;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
		float toFloat(void) const;
		int toInt(void) const;
};