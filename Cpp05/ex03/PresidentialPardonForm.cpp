#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("PresidentialPardonForm", 25, 5){
	_target = target;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(Form const & f) :
Form("PresidentialPardonForm", 25, 5){
	_target = f.getTarget();
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	return;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!getSignedState() || !canExecute(executor))
		return;
	
	std::cout << _target << " has been pardoned by Zafod Beeblebrox."
		<< std::endl;
	return;
}
