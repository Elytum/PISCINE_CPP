#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :
	Form( "PresidentialPardonForm", 25, 5 ), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & cpy) :
	Form( "PresidentialPardonForm", 25, 5 ), target(cpy.getTarget()) {
}

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form( "PresidentialPardonForm", 25, 5 ), target("Nobody") {
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
}

void	PresidentialPardonForm::launch( void ) const {
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

const std::string	PresidentialPardonForm::getTarget( void ) const {
	return target;
}
