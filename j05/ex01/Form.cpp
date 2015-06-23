#include "Form.hpp"
#include <stdexcept>

void				Form::checkGrade( void ) const {
	if (requirementSign < 1)
		throw Form::GradeTooHighException();
	else if (requirementSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const std::string name, int requirementSign, int requirementExec ) :
	name(name), wasSigned(false), requirementSign(requirementSign), requirementExec(requirementExec)	{
	checkGrade();
}

Form::Form( Form const & cpy) : name(cpy.getName()), wasSigned(cpy.getWasSigned()),
requirementSign(cpy.getRequirementSign()), requirementExec(cpy.getRequirementExec())	{
	checkGrade();
}

Form::~Form() {
}

std::string			Form::getName( void ) const {
	return name;
}

bool				Form::getWasSigned( void ) const {
	return wasSigned;
}

int					Form::getRequirementSign( void ) const {
	return requirementSign;
}

int					Form::getRequirementExec( void ) const {
	return requirementExec;
}

std::ostream&		operator<<(std::ostream& flux, Form const & talking)	{
	if (talking.getWasSigned())
		flux << "The formular " << talking.getName() << " has been signed. The grade " << talking.getRequirementSign() << " was required to sign it.";
	else
		flux << "The formular " << talking.getName() << " isn't signed. The grade " << talking.getRequirementSign() << " is required to sign it.";
	flux << " The grade required to execute it is " << talking.getRequirementExec() << "." << std::endl;
	return (flux);
}

void				Form::beSigned( Bureaucrat const & P_L_E_A_S_E_Agent ) {
	if (P_L_E_A_S_E_Agent.getGrade() > requirementSign)
		throw Form::GradeTooLowException();
	wasSigned = true;
}

Form&				Form::operator=(Form const & cpy) {
	wasSigned = cpy.getWasSigned();
	return *this;
}

	//	Exception too high
const char *Form::GradeTooHighException::what( void ) const throw() {
	return ("Form: GradeTooHigh");
}

Form::GradeTooHighException::GradeTooHighException( void ) : std::exception() {
}

Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & cpy ) : std::exception() {
	*this = cpy;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {
}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(Form::GradeTooHighException const & cpy){
	(void)cpy;
	return *this;
}

	//	Exception too low
const char *Form::GradeTooLowException::what( void ) const throw() {
	return ("Form: GradeTooLow");
}

Form::GradeTooLowException::GradeTooLowException( void ) : std::exception() {
}

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & cpy ) : std::exception() {
	*this = cpy;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {
}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(Form::GradeTooLowException const & cpy){
	(void)cpy;
	return *this;
}
