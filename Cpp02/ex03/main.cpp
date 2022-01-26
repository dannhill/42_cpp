#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b,
Point const c, Point const point);

int	main(void){
	Point	a('A', 10.0, 20.0);
	Point	b('B', 33.0, 44.0);
	Point	c('C', 11.0, 66.0);
	Point	point('P', 11.0, 22.0);

	std::cout << bsp(a, b, c, point) << std::endl;

	return 0;
}
