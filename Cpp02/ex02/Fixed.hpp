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
		Fixed(unsigned int raw);
		~Fixed(void);

		Fixed &	operator=(Fixed const & fixed);
		bool	operator>(Fixed const & fixed);
		bool	operator<(Fixed const & fixed);
		bool	operator>=(Fixed const & fixed);
		bool	operator<=(Fixed const & fixed);
		bool	operator==(Fixed const & fixed);
		bool	operator!=(Fixed const & fixed);
		Fixed	operator+(Fixed const & fixed);
		Fixed	operator-(Fixed const & fixed);
		Fixed	operator*(Fixed const & fixed);
		Fixed	operator/(Fixed const & fixed);
		Fixed &	operator++(void);
		Fixed 	operator++(int);
		Fixed &	operator--(void);
		Fixed 	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed & a, Fixed & b);
		static const Fixed &	min(const Fixed & a, const Fixed & b);
		static Fixed &			max(Fixed & a, Fixed & b);
		static const Fixed &	max(const Fixed & a, const Fixed & b);
	private:
		int		_fpValue;

		static const int	_fBits;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);