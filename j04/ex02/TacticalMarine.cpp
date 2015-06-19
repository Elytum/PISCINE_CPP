#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine( void ) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine( void ) {
	std::cout << "For the holy PLOT !" << std::endl;
}

void				TacticalMarine::TacticalMarine::battleCry( void ) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void				TacticalMarine::TacticalMarine::rangedAttack( void ) const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void				TacticalMarine::TacticalMarine::meleeAttack( void ) const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

TacticalMarine&		TacticalMarine::operator=(TacticalMarine const & arg) {
	return (*this);
	(void)arg;
}

ISpaceMarine*		TacticalMarine::clone( void ) const {
	ISpaceMarine*		cpy = new TacticalMarine;

	return cpy;
}
