#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void){
	Bureaucrat	*b = new Bureaucrat("Caio", -22);
	Bureaucrat	c("Lawrence", 3);
	Bureaucrat	d;
	Form	f;
	Form	g("pasta", 70, 30);

	std::cout << f << std::endl;
	f.beSigned(c);
	std::cout << f << std::endl;
	f.beSigned(*b);
	std::cout << f << std::endl;

	std::cout << g << std::endl;
	b->signForm(g);
	std::cout << g << std::endl;
	c.signForm(g);
	std::cout << g << std::endl;

	delete b;
	return 0;
}
