#pragma once
#include "Form.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(Form const & f);
		virtual ~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const;
	private:
		PresidentialPardonForm(void);
};