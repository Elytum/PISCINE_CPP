#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void ) : intern(NULL), signer(NULL), executer(NULL) {
}

OfficeBlock::OfficeBlock( Intern &intern, Bureaucrat &signer, Bureaucrat &executer ) :
	intern(&intern), signer(&signer), executer(&executer)	{
}

OfficeBlock::~OfficeBlock( void ) {
}

void		OfficeBlock::setIntern(Intern &ptr) {
	intern = &ptr;
}

void		OfficeBlock::setSigner(Bureaucrat &ptr) {
	signer = &ptr;
}

void		OfficeBlock::setExecutor(Bureaucrat &ptr) {
	executer = &ptr;
}

void		OfficeBlock::doBureaucracy(std::string const & name, std::string const & target) const {
	Form*	form;

	if (!intern)
		std::cout << "Intern not set, OfficeBlock not able to create the formular !" << std::endl;
	else if (!signer)
		std::cout << "Signer not set, OfficeBlock not able to sign the formular !" << std::endl;
	else if (!executer)
		std::cout << "Executer not set, OfficeBlock not able to execute the formular !" << std::endl;
	else {
		if (!(form = intern->makeForm(name, target)))
			throw OfficeBlock::UnknownForm();
		if (!signer->signForm(*form))
			throw OfficeBlock::CantSign();
		if (!executer->executeForm(*form))
			throw OfficeBlock::CantExec();
	}
}

	//	Exception unknown form
const char *OfficeBlock::UnknownForm::what( void ) const throw() {
	return ("OfficeBlock: UnnownForm");
}

OfficeBlock::UnknownForm::UnknownForm( void ) : std::exception() {
}

OfficeBlock::UnknownForm::UnknownForm( OfficeBlock::UnknownForm const & cpy ) : std::exception() {
	*this = cpy;
}

OfficeBlock::UnknownForm::~UnknownForm( void ) throw() {
}

OfficeBlock::UnknownForm& OfficeBlock::UnknownForm::operator=(OfficeBlock::UnknownForm const & cpy){
	(void)cpy;
	return *this;
}

	//	Exception can't sign
const char *OfficeBlock::CantSign::what( void ) const throw() {
	return ("OfficeBlock: CantSign");
}

OfficeBlock::CantSign::CantSign( void ) : std::exception() {
}

OfficeBlock::CantSign::CantSign( OfficeBlock::CantSign const & cpy ) : std::exception() {
	*this = cpy;
}

OfficeBlock::CantSign::~CantSign( void ) throw() {
}

OfficeBlock::CantSign& OfficeBlock::CantSign::operator=(OfficeBlock::CantSign const & cpy){
	(void)cpy;
	return *this;
}

	//	Exception can't exec
const char *OfficeBlock::CantExec::what( void ) const throw() {
	return ("OfficeBlock: CantExec");
}

OfficeBlock::CantExec::CantExec( void ) : std::exception() {
}

OfficeBlock::CantExec::CantExec( OfficeBlock::CantExec const & cpy ) : std::exception() {
	*this = cpy;
}

OfficeBlock::CantExec::~CantExec( void ) throw() {
}

OfficeBlock::CantExec& OfficeBlock::CantExec::operator=(OfficeBlock::CantExec const & cpy){
	(void)cpy;
	return *this;
}
