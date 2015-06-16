#include "Human.hpp"

Human::Human( void ) {
	this->brain = Brain();
}

Human::~Human( void ) {
}

std::string	Human::identify( void ) const {
	return (this->brain.identify());
}

Brain		&Human::getBrain( void ) {
	return (this->brain);
}
