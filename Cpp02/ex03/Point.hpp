#pragma once
#include "Fixed.hpp"

class Point{
	public:
		Point(void);
		Point(const Point & point);
		Point(const float x, const float y);
		~Point(void);

		Point &	operator=(Point const & point);
	private:
		Fixed const	_x;
		Fixed const	_y;
};