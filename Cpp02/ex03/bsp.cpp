#include "Point.hpp"
//in sospeso perchè non so se posso inserire getter
class Global{
	public:
		Global(const Fixed a, const Fixed b) : m(a), q(b){}
		const Fixed	m;
		const Fixed	q;
};

Global	*glbl = NULL;

Fixed	detectDistance(Point const a, Point const b);
Fixed &	exToEpsilon(Fixed & x);
Point const &	furthest(Point const &a, Point const &b,
Point const &c, Point const &point);

Fixed &	exToEpsilon(Fixed & x){

	if (glbl == NULL)
	{
		std::cout << "Error: global variable glbl not initialized. Aborting." << std::endl;
		exit(1);
	}
	x = x * glbl->m + glbl->q;
	return x;
}

Fixed &	getQ(Point const & point, Fixed m){
	return *(new Fixed(point.getY() - m * point.getX()));
}

Point const &	furthest(Point const &a, Point const &b,
Point const &c, Point const &point){
	int		max(0);
	Fixed	fmax(0);
	const Point	*tri[3] = {&a, &b, &c};

	for (int i(0); i < 3; i++)
		if (detectDistance(point, *tri[i]) >= detectDistance(point, *tri[max]))
			max = i;
	return	*tri[max];
}

Fixed	detectDistance(Point const a, Point const b){
	Fixed	aa;
	Fixed	bb;

	aa = (a.getX() - b.getX()) * (a.getX() - b.getX());
	bb = (a.getY() - b.getY()) * (a.getY() - b.getY());

	return aa + bb;
}

// bool	bsp(Point const a, Point const b,
// Point const c, Point const point){
	
// 	return true;
// }

int	main(void){
	Global	gl(20, 30);
	glbl = &gl;
	Point	a('A', 10.0, 20.0);
	Point	b('B', 33.0, 44.0);
	Point	c('C', 11.0, 66.0);
	Point	point('P', 41.03, 66.89);
	Fixed	q;

	Fixed	x(20);

	std::cout << furthest(a, b, c, point).getTag() << std::endl;

	{
		Fixed	m((c.getY() - b.getY()).toFloat() / (c.getX() - b.getX()).toFloat());
		q = Fixed(-1) * m * b.getX() + b.getY();
		Global	gl(m, q);
		glbl = &gl;
	}

	std::cout << "m: " << gl.m << std::endl;
	std::cout << "q: " << gl.q << std::endl;

	std::cout << exToEpsilon(x) << std::endl;

	std::cout << getQ(point, gl.m) << std::endl;
	std::cout << getQ(c, gl.m) << std::endl;

	return 0;
}