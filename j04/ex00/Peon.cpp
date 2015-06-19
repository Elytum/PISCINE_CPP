#include "Peon.hpp"

Peon::Peon( std::string name ) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const & cpy ) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
	(*this) = cpy;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

// std::string		Peon::getName( void ) const {
// 	return name;
// }

// void			Peon::setName( std::string const arg ) {
// 	name = arg;
// }

void			Peon::getPolymorphed() const {
	std::cout << name << " has been turned into a pink pony !" << std::endl;
}

// Peon&	Peon::operator=(Peon const & arg) {
// 	name = arg.getName();
// 	return (*this);
// }

// std::ostream &operator<<(std::ostream& flux, const Peon& arg)  {
// 	flux << "I am " << arg.getName() << " and I like otters !" << std::endl;
// 	return (flux);
// }
