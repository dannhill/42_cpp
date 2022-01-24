#include "Intern.hpp"

std::string	Intern::_formNamez[3] = {"shrubbery creation",
"robotomy request", "presidential pardon"};

Intern::Intern(void){
	return;
}

Intern::~Intern(void){
	return;
}

Form	*Intern::makeForm(std::string formType, std::string target) const{
	int	i(0);

	for (; i < 3; i++)
		if(_formNamez[i] == formType)
			break;
	try{
		switch(i)
		{
			case 0:
				std::cout << "Intern creates shrubbery creation form" << std::endl;
				return new ShrubberyCreationForm(target);
			case 1:
				std::cout << "Intern creates robotomy request form" << std::endl;
				return new RobotomyRequestForm(target);
			case 2:
				std::cout << "Intern creates presidential pardon form" << std::endl;
				return new PresidentialPardonForm(target);
			default:
				throw FormNotFoudException();
				break;
		}
	}
	catch (FormNotFoudException & f){
		std::cerr << f.what() << std::endl;
		exit(1);
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}
