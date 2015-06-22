#include "Bureaucrat.hpp"
#include <iostream>

int			main(void)
{
	int		somebodyGrade = 42;
	Bureaucrat	someTemplate("Someone", somebodyGrade);

	try {
		Bureaucrat	somebody("Someone", 50);

		somebody = someTemplate;
		std::cout << somebody;
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	someone_too_low("Someone", 200);
		std::cout << someone_too_low;
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	someone_too_low("Someone", 0);
		std::cout << someone_too_low;
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	somebody("Someone", somebodyGrade);
		while (true) {
			somebody.promote();
			std::cout << somebody;
		}
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	somebody("Someone", somebodyGrade);
		while (true) {
			somebody.demote();
			std::cout << somebody;
		}
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
