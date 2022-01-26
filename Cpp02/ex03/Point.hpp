#pragma once
#include "Fixed.hpp"

class Point{
	public:
		Point(void);
		Point(const Point & point);
		Point(char tag, const Point & point);
		Point(const float x, const float y);
		Point(char tag, const float x, const float y);
		~Point(void);

		Point &	operator=(Point const & point);

		Fixed &	getX(void) const;
		Fixed &	getY(void) const;
		char	getTag(void) const;
		void	setTag(char c);

	private:
		Fixed const	_x;
		Fixed const	_y;
		char	_tag;
};
