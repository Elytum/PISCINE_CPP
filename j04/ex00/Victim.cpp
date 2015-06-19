#include "Victim.hpp"

Victim::Victim( void ) : name("Unknown") {
	std::cout << name << ", is not born, what did you expect ?" << std::endl;
}

Victim::Victim( std::string name ) : name(name) {
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim( Victim const & cpy ) {
	(*this) = cpy;
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
}

std::string		Victim::getName( void ) const {
	return name;
}

void			Victim::getPolymorphed() const {
	std::cout << name << " has been turned into a cute little sheep !" << std::endl;
}

Victim&	Victim::operator=(Victim const & arg) {
	name = arg.getName();
	return (*this);
}

std::ostream &operator<<(std::ostream& flux, const Victim& arg)  {
	flux << "I'm " << arg.getName() << " and I like otters !" << std::endl;
	return (flux);
}
