#include "Point.hpp"
//in sospeso perchè non so se posso inserire getter
class Global{
	public:
		Global(const Fixed a, const Fixed b) : m(a), q(b){}
		const Fixed	m;
		const Fixed	q;
};

Global	*glbl = NULL;

Fixed &	exToEpsilon(Fixed & x){

	if (glbl == NULL)
	{
		std::cout << "Error: global variable glbl not initialized. Aborting." << std::endl;
		exit(1);
	}
	x = x * glbl->m + glbl->q;
	return x;
}

Fixed	detectDistance(Point const a, Point const b){
	Fixed 	res;
	Fixed	aa;
	Fixed	bb;

	return res = 
}

bool	bsp(Point const a, Point const b,
Point const c, Point const point){



	return true;
}

int	main(void){
	Global	gl(20, 30);
	glbl = &gl;

	Fixed	x(20);

	std::cout << exToEpsilon(x) << std::endl;

	return 0;
}