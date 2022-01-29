#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b,
Point const c, Point const point);

int	main(void){
	Point	a('A', 10.0, 20.0);
	Point	b('B', 33.0, 44.0);
	Point	c('C', 11.0, 66.0);
	Point	point('P', 11.0, 22.0);

	std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;

	Point	aa('A', -10, 0);
	Point	bb('B', 10, 0);
	Point	cc('C', 0, 30);
	Point	ppoint('P', -2, 3);	

	std::cout << std::boolalpha << bsp(aa, bb, cc, ppoint) << std::endl;

	Point	a1('A', -10, 30);
	Point	b1('B', -10, 0);
	Point	c1('C', 10, 30);
	Point	point1('P', -4, 7);	

	std::cout << std::boolalpha << bsp(a1, b1, c1, point1) << std::endl;

	Point	a2('A', -10, 30);
	Point	b2('B', -10, 0);
	Point	c2('C', 10, 30);
	Point	point2('P', -10, 10);

	std::cout << std::boolalpha << bsp(a2, b2, c2, point2) << std::endl;

	return 0;
}
