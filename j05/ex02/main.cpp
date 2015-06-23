#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int			main(void)
{
	Bureaucrat					ArthurDent("Arthur Dent", 20);
	Bureaucrat					HummaKavula("Humma Kavula", 5);
	Bureaucrat					FordPrefect("Ford Prefect", 12);
	Bureaucrat					ZafodBeeblebrox("Zafod Beeblebrox", 2);
	Bureaucrat					Mice("Mice", 1);
	PresidentialPardonForm		TriciaMcmillanLiberationForm("Tricia Mcmillan");
	ShrubberyCreationForm		SomethingShrubberyCreationForm("Something");
	RobotomyRequestForm			ArthurDentRobotomyRequestForm("Arthur Dent");

	std::cout << "Bureaucrat ArthurDent(\"Arthur Dent\", 140);" << std::endl << ArthurDent;
	std::cout << "Bureaucrat Humma Kavula(\"Humma Kavula\", 5);" << std::endl << HummaKavula;
	std::cout << "Bureaucrat Ford Prefect(\"Ford Prefect\", 140);" << std::endl << FordPrefect;
	std::cout << "Bureaucrat ZafodBeeblebrox(\"Zafod Beeblebrox\", 2);" << std::endl << ZafodBeeblebrox;
	std::cout << "Bureaucrat Mice(\"Mice\", 1);" << std::endl << Mice;
	std::cout << "PresidentialPardonForm TriciaMcmillanLiberationForm(\"TriciaMcmillan\");" << std::endl << TriciaMcmillanLiberationForm;
	std::cout << "ShrubberyCreationForm SomethingShrubberyCreationForm(\"Something\");" << std::endl << SomethingShrubberyCreationForm;
	std::cout << "RobotomyRequestForm ArthurDentRobotomyRequestForm(\"ArthurDent\");" << std::endl << ArthurDentRobotomyRequestForm << std::endl << std::endl;
	
	ArthurDent.signForm(TriciaMcmillanLiberationForm);
	ZafodBeeblebrox.signForm(TriciaMcmillanLiberationForm);
	ArthurDent.executeForm(TriciaMcmillanLiberationForm);
	ZafodBeeblebrox.executeForm(TriciaMcmillanLiberationForm);
	FordPrefect.signForm(SomethingShrubberyCreationForm);
	HummaKavula.executeForm(SomethingShrubberyCreationForm);
	Mice.signForm(ArthurDentRobotomyRequestForm);
	Mice.executeForm(ArthurDentRobotomyRequestForm);
}
