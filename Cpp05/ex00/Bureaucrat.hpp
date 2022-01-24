#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & bureau);
		Bureaucrat(std::string name, int const grade);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & bureau);

		std::string const	getName(void) const;
		int	getGrade(void) const;

		void	upGrade(void);
		void	downGrade(void);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Error: Grade of bureaucrat too high!!!";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Error: Grade of bureaucrat too low!!!";
				}
		};
	private:
		std::string const	_name;
		int	_grade;

		void	_setGrade(int const grade);

		static int const	_max_grade;
		static int const	_min_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & bureau);
