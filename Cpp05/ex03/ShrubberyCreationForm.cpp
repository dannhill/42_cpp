#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("ShrubberyCreationForm", 145, 137){
	_target = target;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(Form const & f) :
Form("ShrubberyCreationForm", 145, 137){
	_target = f.getTarget();
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	return;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream	out;

	if (!getSignedState() || !canExecute(executor))
		return;

	out.open((this->getTarget() + "_shrubbery").c_str());
	out <<
"                                                         .      \n"
"                                              .         ;       \n"
"                 .              .              ;%     ;;        \n"
"                   ,           ,                :;%  %;         \n"
"                    :         ;                   :;%;'     .,  \n"
"           ,.        %;     %;            ;        %;'    ,;    \n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'     \n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'      \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'        \n"
"                `%;.     ;%;     %;'         `;%%;.%;'          \n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'             \n"
"                    `:%;.  :;bd%;          %;@%;'               \n"
"                      `@%:.  :;%.         ;@@%;'                \n"
"                        `@%.  `;@%.      ;@@%;                  \n"
"                          `@%%. `@%%    ;@@%;                   \n"
"                            ;@%. :@%%  %@@%;                    \n"
"                              %@bd%%%bd%%:;                     \n"
"                                #@%%%%%:;;                      \n"
"                                %@@%%%::;                       \n"
"                                %@@@%(o);  . '                  \n"
"                                %@@@o%;:(.,'                    \n"
"                            `.. %@@@o%::;                       \n"
"                               `)@@@o%::;                       \n"
"                                %@@(o)::;                       \n"
"                               .%@@@@%::;                       \n"
"                               ;%@@@@%::;.                      \n"
"                              ;%@@@@%%:;;;.                     \n"
"                          ...;%@@@@@%%:;;;;,..                  \n";
	out.close();
	return;
}
