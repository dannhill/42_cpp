#pragma once
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(Form const & f);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;
	private:
		ShrubberyCreationForm(void);
};
