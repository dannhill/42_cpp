#pragma once
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <string>

class Intern{
	public:
		Intern(void);
		Intern(Intern const & cpy);
		~Intern(void);

		Form	*makeForm(std::string formType, std::string target) const;
		

		Intern &	operator=(Intern const & asn);
		class FormNotFoudException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Error: form not found.";
				}
		};
	private:
		static const std::string	_formNamez[3];
};