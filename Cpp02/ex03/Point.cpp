#include "Point.hpp"

Point::Point(void) : _x(0), _y(0), _tag('d'){
	return;
}

Point::Point(const Point & point) : _x(point._x), _y(point._y), _tag('p'){
	return;
}

Point::Point(char tag, const Point & point) : _x(point._x), _y(point._y), _tag(tag){
	return;
}

Point::Point(const float x, const float y) : _x(x), _y(y), _tag('f'){
	return;
}

Point::Point(char tag, const float x, const float y) : _x(x), _y(y), _tag(tag){
	return;
}

Point::~Point(void){
	return;
}

Point &	Point::operator=(Point const & point){
	//da chiedere a gli altri. x e y sono const, e dovrebbero essere modificati	
	Fixed	*xx = const_cast<Fixed *>(&_x);
	Fixed	*yy = const_cast<Fixed *>(&_y);

	*xx = point._x;
	*yy = point._y;
	setTag(point.getTag());
	return *this;
}

Fixed &	Point::getX(void) const{
	return *(const_cast<Fixed *>(&_x));
}

Fixed &	Point::getY(void) const{
	return *(const_cast<Fixed *>(&_y));
}

char	Point::getTag(void) const{
	return _tag;
}

void	Point::setTag(char c){
	_tag = c;
}
