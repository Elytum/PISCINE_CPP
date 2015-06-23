#include "Intern.hpp"

Intern::Intern( void ) {
}

Intern::~Intern( void ) {
}

Form*	Intern::makeForm(std::string const & formKind, std::string const & target) {
	if (formKind == "presidential pardon") {
		std::cout << "Intern creates a presidential pardon form." << std::endl;
		return new PresidentialPardonForm(target);
	} else if (formKind == "robotomy request") {
		std::cout << "Intern creates a robotomy request form." << std::endl;
		return new RobotomyRequestForm(target);
	} else if (formKind == "shrubbery creation") {
		std::cout << "Intern creates a shrubbery creation form." << std::endl;
		return new ShrubberyCreationForm(target);
	} else {
		std::cout << "Intern doesn't know the " << formKind << " form." << std::endl;
		return NULL;
	}
}