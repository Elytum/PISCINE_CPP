#include "Peon.hpp"

Peon::Peon( void ) : name("Unknown") {
	std::cout << name << ", is not born, what did you expect ?" << std::endl;
}

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

void			Peon::getPolymorphed() const {
	std::cout << name << " has been turned into a pink pony !" << std::endl;
}
