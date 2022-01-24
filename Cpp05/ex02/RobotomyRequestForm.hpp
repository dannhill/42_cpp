#pragma once
#include "Form.hpp"
#include <unistd.h>
#include <cstdlib>

class RobotomyRequestForm : public Form{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(Form const & f);
		~RobotomyRequestForm(void);

		void	execute(Bureaucrat const & executor) const;

		static int	randVar(int v);
	private:
		RobotomyRequestForm(void);
		static bool	_r_init;
};
