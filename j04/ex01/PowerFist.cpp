#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 50, 8) {
}

PowerFist::~PowerFist( void ) {
}

void	PowerFist::attack( void ) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}