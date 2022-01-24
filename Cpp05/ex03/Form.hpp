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
		virtual	~Form(void);

		virtual void	beSigned(Bureaucrat const & b);
		virtual	bool	canExecute(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool	getSignedState(void) const;
		std::string	getTarget(void) const;

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
	protected:
		std::string const	_name;
		int const	_sign_grade;
		int const	_exec_grade;
		bool		_is_signed;
		bool		_is_exec;
		std::string	_target;
};

std::ostream &	operator<<(std::ostream & o, Form const & f);
