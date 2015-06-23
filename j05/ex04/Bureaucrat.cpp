#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( const std::string & name, int grade ) : name(name), grade(grade)	{
	checkGrade();
}

Bureaucrat::Bureaucrat( Bureaucrat const & cpy) : name(cpy.getName()), grade(cpy.getGrade())	{
	checkGrade();
}

Bureaucrat::~Bureaucrat() {
}

std::string			Bureaucrat::getName( void ) const {
	return name;
}

int					Bureaucrat::getGrade( void ) const {
	return grade;
}

void				Bureaucrat::promote( void ) {
	grade--;
	checkGrade();
}

void				Bureaucrat::demote( void ) {
	grade++;
	checkGrade();
}

void				Bureaucrat::checkGrade( void ) const {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&			Bureaucrat::operator=(Bureaucrat const & cpy)	{
	grade = cpy.getGrade();
	checkGrade();
	return *this;
}

bool				Bureaucrat::executeForm(Form const & form) const	{
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << name << " (Grade " << grade << ") executes a " << form.getName()
		<<	" (s.grade " << form.getRequirementSign() << ", ex.grade " << form.getRequirementExec()
		<< ") targeted on " << form.getTarget() << " (Signed)." << std::endl;
		form.launch();
		return true;
	} catch (Form::GradeTooLowException) {
		std::cout << "The formular " << form.getName() << " was not executed because it's executor grade is too low." << std::endl;
	} catch (Form::NotSignedException) {
		std::cout << "The formular " << form.getName() << " was not executed because it wasn't signed yet." << std::endl;
	} catch (std::exception) {
		std::cout << "The formular " << form.getName() << " was not executed because of an unknown reason." << std::endl;
	}
	return false;
}

bool				Bureaucrat::signForm( Form & form ) const {
	try {
		bool	wasSigned = form.getWasSigned();

		form.beSigned(*this);
		std::cout << "Bureaucrat " << name << " (Grade " << grade << ") signs a " << form.getName()
		<< " (s.grade " << form.getRequirementSign() << ", ex.grade " << form.getRequirementExec()
		<< ") targeted on " << form.getTarget();
		if (wasSigned)
			std::cout << " (Signed)." << std::endl;
		else
			std::cout << " (Unsigned)." << std::endl;
		return true;
		
	} catch (Form::GradeTooLowException) {
		std::cout << "Bureaucrat " << name << " cannot sign " << form.getName() << " because his grade is too low (His grade is "
			<< grade << " but should be at least " << form.getRequirementSign() << ")." << std::endl;
	} catch (std::exception) {
		std::cout << "Bureaucrat " << name << " cannot sign " << form.getName() << " because of an unknown reason." << std::endl;
	}
	return false;
}

std::ostream&		operator<<(std::ostream& flux, Bureaucrat const & talking)	{
	flux << talking.getName() << ", bureaucrat grade " << talking.getGrade() << "." << std::endl;
	return (flux);
}


	//	Exception too high
const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Bureaucrat: GradeTooHigh");
}

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) : std::exception() {
}

Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & cpy ) : std::exception() {
	*this = cpy;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & cpy){
	(void)cpy;
	return *this;
}

	//	Exception too low
const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Bureaucrat: GradeTooLow");
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) : std::exception() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & cpy ) : std::exception() {
	*this = cpy;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & cpy){
	(void)cpy;
	return *this;
}
