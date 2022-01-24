#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_r_init(false);

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("RobotomyRequestForm", 72, 45){
	if (!_r_init)
	{
		srand(time(NULL));
		_r_init = true;
	}
	_target = target;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(Form const & f) :
Form("RobotomyRequestForm", 72, 45){
	if (!_r_init)
	{
		srand(time(NULL));
		_r_init = true;
	}
	_target = f.getTarget();
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	return;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!getSignedState() || !canExecute(executor))
		return;
	
	int	r(-1);

	std::cout << "Drrrrr" << std::flush;
	usleep(500000 + randVar(200000));
	std::cout << "." << std::flush;
	usleep(500000 + randVar(200000));
	std::cout << "." << std::flush;
	usleep(500000 + randVar(200000));
	std::cout << "." << std::flush;
	usleep(500000 + randVar(200000));
	std::cout << "." << std::endl;

	r = rand() % 2;

	if (r == 0)
		std::cout << _target << " has been robotomized "
			"successfully!!" << std::endl;
	else if (r == 1)
		std::cout << _target << " robotomization has been"
			" failed successfully!! :c" << std::endl;
	else if (r < 0)
		std::cerr << "Error: rng failure" << std::endl;
	return;
}

int	RobotomyRequestForm::randVar(int v){
	int	r(0);

	r = rand() % v;
	return (rand() % 2 ? r : -r);
}
