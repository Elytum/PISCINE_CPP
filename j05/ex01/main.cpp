#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int			main(void)
{
	Form			paper("Piece of paper", 150, 150);
	Bureaucrat		barneyStinson("Barney Stinson", 2);

	std::cout << "Printing \"paper(\"Piece of paper\", 150, 150);\": " << paper;
	barneyStinson.signForm(paper);
	std::cout << "Printing \"paper(\"Piece of paper\", 150, 150);\": " << paper;

	Form			law("Law", 1, 1);
	std::cout << "Printing \"paper(\"Law\", 1, 1);\": " << law;
	barneyStinson.signForm(law);
	std::cout << "Printing \"paper(\"Law\", 1, 1);\": " << law;

	try {
		std::cout << "Trying to create \"something(\"something\", 151, 151);\"" << std::endl;
		Form			something("something", 151, 151);
	} catch (Form::GradeTooLowException & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to create \"something(\"something\", 0, 0);\"" << std::endl;
		Form			something("something", 0, 0);
	} catch (Form::GradeTooHighException & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
