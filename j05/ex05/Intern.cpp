#include "Intern.hpp"

Intern::Intern( void ) {
}

Intern::~Intern( void ) {
}

Form*	Intern::makeForm(std::string const & formKind, std::string const & target) {
	Form	*form;

	if (formKind == "presidential pardon") {
		std::cout << "Intern creates a Presidential Pardon Form " << std::endl;
		form = new PresidentialPardonForm(target);
	} else if (formKind == "robotomy request") {
		std::cout << "Intern creates a Robotomy Request Form " << std::endl;
		form = new RobotomyRequestForm(target);
	} else if (formKind == "shrubbery creation") {
		std::cout << "Intern creates a Shrubbery Creation Form " << std::endl;
		form = new ShrubberyCreationForm(target);
	} else {
		std::cout << "Intern doesn't know the " << formKind << " form." << std::endl;
		return NULL;
	}
	std::cout << "(s.grade " << form->getRequirementSign() << ", ex.grade " << form->getRequirementExec()
		<< ") targeted on " << target << " (Unsigned)" << std::endl;
	return (form);
}