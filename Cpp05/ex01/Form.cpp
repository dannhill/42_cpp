#include "Form.hpp"

Form::Form(void) : is_signed(false), _name("AAA"),
 _sign_grade(100), _exec_grade(50){
	return;
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
is_signed(false), _name(name), _sign_grade(sign_grade),
_exec_grade(exec_grade){
	return;
}

Form::Form(Form const & f) : is_signed(false), _name(f.getName()),
_sign_grade(f.getSignGrade()), _exec_grade(f.getExecGrade()){
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
			is_signed = true;
	}
	catch (Form::GradeTooLowException & l){
		std::cerr << l.what() << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
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

std::ostream &	operator<<(std::ostream & o, Form const & f){
	return o << "Form " << f.getName() << ", minimum sign grade " <<
		f.getSignGrade() << ", minimum exec grade " << f.getExecGrade() <<
		", state " << (f.is_signed ? "signed." : "unsigned.");
}
