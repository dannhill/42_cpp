#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void){
	Bureaucrat	*b = new Bureaucrat("Caio", -22);
	Bureaucrat	c("Lawrence", 3);
	Bureaucrat	d;
	ShrubberyCreationForm	s("kabiro");
	RobotomyRequestForm		r("kek");
	PresidentialPardonForm	p("JoJo");

	std::cout << s << std::endl;
	s.execute(c);
	std::cout << s << std::endl;

	c.signForm(r);
	b->executeForm(r);
	c.executeForm(r);
	c.signForm(p);
	d.executeForm(p);
	c.executeForm(p);
	d.executeForm(s);
	d.signForm(s);
	c.signForm(s);
	d.executeForm(s);
	c.executeForm(s);

	delete b;
	return 0;
}
