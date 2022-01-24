#include "Bureaucrat.hpp"

int const	Bureaucrat::_max_grade(1);
int const	Bureaucrat::_min_grade(150);

Bureaucrat::Bureaucrat(void) : _name("Kratos"), _grade(150){
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & bureau) : _name(bureau.getName()),
_grade(150){
	_setGrade(bureau.getGrade());
	return;
}

Bureaucrat::Bureaucrat(std::string name, int const grade) : _name(name),
_grade(150){
	_setGrade(grade);
	return;
}

Bureaucrat::~Bureaucrat(void){
	return;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & bureau){
	this->_setGrade(bureau.getGrade());
	return *this;
}

std::string const	Bureaucrat::getName(void) const{
	return _name;
}

int	Bureaucrat::getGrade(void) const{
	return _grade;
}

void	Bureaucrat::upGrade(void){
	this->_setGrade(this->getGrade() - 1);
	return;
}

void	Bureaucrat::downGrade(void){
	this->_setGrade(this->getGrade() + 1);
	return;
}

void	Bureaucrat::signForm(Form & f) const{
	int	grade(this->getGrade());
	int	sgrade(f.getSignGrade());

	try{
		if (grade > sgrade)
			throw GradeTooLowException();
		else if (grade <= sgrade)
		{
			std::cout << this->getName() << " signs " << f.getName() <<
				"." << std::endl;
			f.beSigned(*this);
		}
	}
	catch (GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	Bureaucrat::executeForm(Form const & form) const{
	int	grade(this->getGrade());
	int	egrade(form.getExecGrade());

	try{
		if (grade > egrade)
			throw GradeTooLowException();
		else if (grade <= egrade)
		{
			std::cout << this->getName() << " executes " << form.getName() <<
				"." << std::endl;
			form.execute(*this);
		}
	}
	catch (GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	Bureaucrat::_setGrade(int const grade){
	try{
		if (grade > _min_grade)
			throw GradeTooLowException();
		else if (grade < _max_grade)
			throw GradeTooHighException();
		else
			_grade = grade;
	}
	catch (GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (GradeTooHighException & h){
		std::cerr << h.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & bureau){
	return o << bureau.getName() << ", bureaucrat grade " << bureau.getGrade()
		<< ".";
}
