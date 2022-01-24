#pragma once
#include <iostream>

class Fixed{
	public:
		Fixed(void);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		Fixed &	operator=(Fixed const & fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int		_fpValue;

		static const int	_fBits;
};