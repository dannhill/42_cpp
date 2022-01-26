#include "Point.hpp"

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

bool	bsp(Point const a, Point const b,
Point const c, Point const point){
	Point	aa('A', a);
	Point	bb('B', b);
	Point	cc('C', c);
	Point const	*tri[3] = {&aa, &bb, &cc};
	char	tag('!');

	tag = furthest(aa, bb, cc, point).getTag();

	Point	ps[2];
	Point	e;

	for (int i(0),j(0) ; i < 3; i++)
	{
		if (tri[i]->getTag() != tag)
		{
			ps[j] = *tri[i];
			j++;
		}
		else if (tri[i]->getTag() == tag)
			e = *tri[i];
	}

	
	Fixed	m((ps[1].getY() - ps[0].getY()).toFloat() / (ps[1].getX() - ps[0].getX()).toFloat());
	Fixed	q = Fixed(-1) * m * ps[0].getX() + ps[0].getY();
	Global	*gl = new Global(m, q);
	glbl = gl;

	if ((getQ(point, glbl->m) - glbl->q) * 
		(getQ(point, glbl->m) - getQ(e, glbl->m)) < 0)
	{
		delete glbl;
		return true;
	}
	else
	{
		delete glbl;
		return false;
	}
}
