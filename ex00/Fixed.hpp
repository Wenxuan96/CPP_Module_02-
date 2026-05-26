#include <iostream>
#include <string>

class Fixed
{
	private:
		int val;
		static const int fractionalBits;
	
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};