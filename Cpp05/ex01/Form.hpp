#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form{
	public:
		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const & f);
		~Form(void);

		void	beSigned(Bureaucrat const & b);

		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool	getSignState(void) const;
		void	setSignState(bool state);
	
		class GradeTooHighException : std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Error: Grade too high for the form!!";
				}
		};
		class GradeTooLowException : std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Error: Grade too low for the form!!";
				}
		};
	private:
		bool		_is_signed;
		std::string const	_name;
		int const	_sign_grade;
		int const	_exec_grade;
};

std::ostream &	operator<<(std::ostream & o, Form const & f);
