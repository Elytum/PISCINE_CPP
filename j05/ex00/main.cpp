#include "Bureaucrat.hpp"

int			main(void)
{
	try {
		Bureaucrat		John("John", 151);
		John.demote();
		std::cout << John << std::endl;
		John.promote();
		std::cout << John << std::endl;
	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat		Peter("Peter", 6);
		Peter.demote();
		std::cout << Peter << std::endl;
		Peter.promote();
		std::cout << Peter << std::endl;
	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat		Peter("Peter", 1);
		Peter.promote();
		std::cout << Peter << std::endl;
		Peter.promote();
		std::cout << Peter << std::endl;
	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}


	return (0);
}
