#include "Squad.hpp"

Squad::Squad( void ) {
	// std::cout << "Tactical Marine ready for battle" << std::endl;
}

Squad::~Squad( void ) {
	// std::cout << "Tactical Marine ready for battle" << std::endl;
}

int				Squad::getCount( void ) const {
	return (count);
}

int				Squad::push( ISpaceMarine* marine ) {
	return (count++);
	(void)marine;
}

ISpaceMarine*	Squad::getUnit( int arg ) const {
	return (0);
	(void)arg;
}