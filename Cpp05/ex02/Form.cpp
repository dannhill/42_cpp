#include "Form.hpp"

Form::Form(void) : _name("AAA"),
_sign_grade(100), _exec_grade(50), _is_signed(false),
_is_exec(false){
	return;
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
_name(name), _sign_grade(sign_grade),
_exec_grade(exec_grade), _is_signed(false), _is_exec(false){
	return;
}

Form::Form(Form const & f) :_name(f.getName()), _sign_grade(f.getSignGrade()),
_exec_grade(f.getExecGrade()), _is_signed(false), _is_exec(false){
	return;
}

Form::~Form(void){
	return;
}

void	Form::beSigned(Bureaucrat const & b){
	int	grade(b.getGrade());
	int	sgrade(this->getSignGrade());

	try{
		if (grade > sgrade)
			throw Form::GradeTooLowException();
		else if (grade <= sgrade)
			_is_signed = true;
	}
	catch (Form::GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

bool	Form::canExecute(Bureaucrat const & executor) const{
	int	grade(executor.getGrade());
	int	egrade(this->getExecGrade());

	try{
		if (grade > egrade)
			throw GradeTooLowException();
		else if (grade <= egrade)
			return true;
	}
	catch (GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return false;
}

std::string	Form::getName(void) const{
	return _name;
}

int	Form::getSignGrade(void) const{
	return _sign_grade;
}

int	Form::getExecGrade(void) const{
	return _exec_grade;
}

bool	Form::getSignedState(void) const{
	return _is_signed;
}

std::string	Form::getTarget(void) const{
	return _target;
}

std::ostream &	operator<<(std::ostream & o, Form const & f){
	return o << "Form " << f.getName() << ", minimum sign grade " <<
		f.getSignGrade() << ", minimum exec grade " << f.getExecGrade() <<
		", state " << (f.getSignedState() ? "signed." : "unsigned.");
}
