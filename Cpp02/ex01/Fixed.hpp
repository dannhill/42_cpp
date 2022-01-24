#pragma once
#include <iostream>
#include <cmath>
//can use roundf function from cmath

class Fixed{
	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		Fixed &	operator=(Fixed const & fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int		_fpValue;

		static const int	_fBits;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);