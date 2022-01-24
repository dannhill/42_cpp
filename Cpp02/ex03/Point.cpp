#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
	return;
}

Point::Point(const Point & point) : _x(point._x), _y(point._y){
	return;
}

Point::Point(const float x, const float y) : _x(x), _y(y){
	return;
}

Point::~Point(void){
	return;
}

// Point &	Point::operator=(Point const & point){
// 	//da chiedere a gli altri. x e y sono const, e dovrebbero essere modificati	
// }
