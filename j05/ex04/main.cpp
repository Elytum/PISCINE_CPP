#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int			main(void)
{
/*
	std::cout << "########## EX00 Test ##########" << std::endl;

	try {
		Bureaucrat					John("John", 151);

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
		Bureaucrat					Peter("Peter", 6);

		Peter.demote();
		std::cout << Peter << std::endl;
		Peter.promote();
		Peter.promote();
		std::cout << Peter << std::endl;

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}
*/

/*
	std::cout << "########## EX01 Test ##########" << std::endl;

	try {
		Bureaucrat					Peter("Peter", 6);
		Form						planeForm("Buy new plane", 5, 3);

		planeForm.beSigned(Peter);
		Peter.signForm(planeForm);
	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form			planeForm("Buy new plane", 5, 3);
		Bureaucrat		Powercrate("Powercrate", 6);
		Powercrate.signForm(planeForm);
		std::cout << planeForm << std::endl;

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}
*/

/*
	std::cout << "########## EX02 Test ##########" << std::endl;

	try {
		Bureaucrat					Peter("Peter", 6);
		Bureaucrat					Powercrate("Powercrate", 1);
		Bureaucrat					Bob("Bob", 50);
		Bureaucrat					John("John", 5);
		Bureaucrat					Marcel("Marcel", 12);

		PresidentialPardonForm		FreeMe("Bob");
		ShrubberyCreationForm		Shrub("Tree");
		RobotomyRequestForm			Robot("Beep");

		// trying signing form
		Peter.signForm(FreeMe);
		Powercrate.signForm(FreeMe);
		Bob.signForm(FreeMe);
		John.signForm(FreeMe);
		Marcel.signForm(FreeMe);
		// trying execute form
		Peter.executeForm(FreeMe);
		Powercrate.executeForm(FreeMe);
		Bob.executeForm(FreeMe);
		John.executeForm(FreeMe);
		Marcel.executeForm(FreeMe);

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}
*/
/*
	std::cout << "########## EX03 Test ##########" << std::endl;

	try {
		Bureaucrat					Peter("Peter", 6);
		Bureaucrat					Powercrate("Powercrate", 1);
		Bureaucrat					Bob("Bob", 50);
		Bureaucrat					John("John", 5);
		Bureaucrat					Marcel("Marcel", 12);
		Intern						Mike;

		Form						*FreeMe = Mike.makeForm("presidential pardon", "Bob");
		Form						*Shrub = Mike.makeForm("shrubbery creation", "Tree");
		Form						*Robot = Mike.makeForm("robotomy request", "Beep");

		// trying signing form
		Peter.signForm(FreeMe);
		Powercrate.signForm(FreeMe);
		Bob.signForm(FreeMe);
		John.signForm(FreeMe);
		Marcel.signForm(FreeMe);
		// trying execute form
		Peter.executeForm(FreeMe);
		Powercrate.executeForm(FreeMe);
		Bob.executeForm(FreeMe);
		John.executeForm(FreeMe);
		Marcel.executeForm(FreeMe);

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) 
		std::cout << e.what() << std::endl;
	}
*/
	std::cout << "########## EX04 Test ##########" << std::endl;
	
	std::cout << ">>>>>>>>>>> TESTING WITH INCORRECT RIGHT <<<<<<<<<<" << std::endl;
	try {
		Intern idiotOne;
		Bureaucrat 							hermes = Bureaucrat("Hermes Conrad", 1);
		Bureaucrat 							bob = Bureaucrat("Bobby Bobson", 123);
		Intern								Mike;

		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		ob.doBureaucracy("shrubbery creation", "toto");
		ob.setExecutor(bob);
		ob.setSigner(hermes);
		ob.doBureaucracy("presidential pardon", "Mikey mouse");

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantSign e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantExec e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::UnknownForm e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << ">>>>>>>>>>> TESTING WITH UNKNOWN FORM <<<<<<<<<<" << std::endl;

	try {
		Intern idiotOne;
		Bureaucrat 							hermes = Bureaucrat("Hermes Conrad", 1);
		Bureaucrat 							bob = Bureaucrat("Bobby Bobson", 1);
		Intern								Mike;

		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		ob.doBureaucracy("shrubbery creation", "toto");
		ob.setExecutor(hermes);
		ob.setSigner(hermes);
		ob.doBureaucracy("presidential pardon", "Mikey mouse");
		ob.doBureaucracy("this is Mickey not Mikey you stupid", "mikey mouse");

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantSign e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantExec e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::UnknownForm e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << ">>>>>>>>>>> TESTING WITH UNSIGNABLE FORM <<<<<<<<<<" << std::endl;

	try {
		Intern idiotOne;
		Bureaucrat 							hermes = Bureaucrat("Hermes Conrad", 150);
		Bureaucrat 							bob = Bureaucrat("Bobby Bobson", 150);
		Intern								Mike;

		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		ob.doBureaucracy("shrubbery creation", "toto");
		ob.setExecutor(hermes);
		ob.setSigner(hermes);
		ob.doBureaucracy("presidential pardon", "Mikey mouse");
		ob.doBureaucracy("this is Mickey not Mikey you stupid", "mikey mouse");

	} catch(Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}	catch(Form::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	} catch(Form::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantSign e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::CantExec e) {
		std::cout << e.what() << std::endl;
	} catch(OfficeBlock::UnknownForm e) {
		std::cout << e.what() << std::endl;
	}
}
