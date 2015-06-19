#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator( void ) {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator( void ) {
	std::cout << "I’ll be back ..." << std::endl;
}

void					AssaultTerminator::battleCry( void ) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void					AssaultTerminator::rangedAttack( void ) const {
	std::cout << "* does nothing *" << std::endl;
}

void					AssaultTerminator::meleeAttack( void ) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

AssaultTerminator&		AssaultTerminator::operator=(AssaultTerminator const & arg) {
	return (*this);
	(void)arg;
}

ISpaceMarine*			AssaultTerminator::clone( void ) const {
	ISpaceMarine*		cpy = new AssaultTerminator;

	return cpy;
}
