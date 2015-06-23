#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int			main(void)
{
	Bureaucrat		ArthurDent("Arthur Dent", 20);
	Bureaucrat		HummaKavula("Humma Kavula", 5);
	Bureaucrat		FordPrefect("Ford Prefect", 12);
	Bureaucrat		ZafodBeeblebrox("Zafod Beeblebrox", 2);
	Bureaucrat		Mice("Mice", 1);

	Intern			Vogon;

	Form*			TriciaMcmillanLiberationForm = Vogon.makeForm("presidential pardon", "Tricia Mcmillan");
	Form*			SomethingShrubberyCreationForm = Vogon.makeForm("shrubbery creation", "Something");
	Form*			ArthurDentRobotomyRequestForm = Vogon.makeForm("robotomy request", "Arthur Dent");
	// Form*			InexistingForm = Vogon.makeForm("Inexisting form", "");

	std::cout << "Bureaucrat ArthurDent(\"Arthur Dent\", 140);" << std::endl << ArthurDent;
	std::cout << "Bureaucrat Humma Kavula(\"Humma Kavula\", 5);" << std::endl << HummaKavula;
	std::cout << "Bureaucrat Ford Prefect(\"Ford Prefect\", 140);" << std::endl << FordPrefect;
	std::cout << "Bureaucrat ZafodBeeblebrox(\"Zafod Beeblebrox\", 2);" << std::endl << ZafodBeeblebrox;
	std::cout << "Bureaucrat Mice(\"Mice\", 1);" << std::endl << Mice;
	std::cout << "Form* TriciaMcmillanLiberationForm = Vogon.makeForm(\"presidential pardon\", \"Tricia Mcmillan\");" << std::endl << *TriciaMcmillanLiberationForm;
	std::cout << "Form* SomethingShrubberyCreationForm = Vogon.makeForm(\"shrubbery creation\", \"Something\");" << std::endl << *SomethingShrubberyCreationForm;
	std::cout << "Form* ArthurDentRobotomyRequestForm = Vogon.makeForm(\"robotomy request\", \"Arthur Dent\");" << std::endl << *ArthurDentRobotomyRequestForm << std::endl << std::endl;
	// std::cout << "Form* InexistingForm = Vogon.makeForm(\"Inexisting form\", \"\");" << std::endl << *InexistingForm << std::endl << std::endl;
	
	ArthurDent.signForm(*TriciaMcmillanLiberationForm);
	ZafodBeeblebrox.signForm(*TriciaMcmillanLiberationForm);
	ArthurDent.executeForm(*TriciaMcmillanLiberationForm);
	ZafodBeeblebrox.executeForm(*TriciaMcmillanLiberationForm);
	FordPrefect.signForm(*SomethingShrubberyCreationForm);
	HummaKavula.executeForm(*SomethingShrubberyCreationForm);
	Mice.signForm(*ArthurDentRobotomyRequestForm);
	Mice.executeForm(*ArthurDentRobotomyRequestForm);
}
