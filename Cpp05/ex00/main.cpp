#include "Bureaucrat.hpp"

int	main(void){
	Bureaucrat	*b = new Bureaucrat("Caio", -22);
	Bureaucrat	c("Lawrence", 3);
	Bureaucrat	d;

	std::cout << c << std::endl;
	c.upGrade();
	std::cout << c << std::endl;
	c.upGrade();
	std::cout << c << std::endl;
	c.upGrade();
	std::cout << c << std::endl;

	std::cout << d << std::endl;
	d.upGrade();
	std::cout << d << std::endl;
	d.upGrade();
	std::cout << d << std::endl;
	d.upGrade();
	std::cout << d << std::endl;
	d.downGrade();
	std::cout << d << std::endl;
	d.downGrade();
	std::cout << d << std::endl;
	d.downGrade();
	std::cout << d << std::endl;
	d.downGrade();
	std::cout << d << std::endl;
	d.downGrade();
	std::cout << d << std::endl;

	std::cout << *b << std::endl;

	delete b;
	return 0;
}
