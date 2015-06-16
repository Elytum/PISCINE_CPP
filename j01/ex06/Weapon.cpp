#include "Weapon.hpp"

Weapon::Weapon( const std::string type ) {
	this->type = type;
}

Weapon::Weapon( void ) {
}

Weapon::~Weapon( void ) {
}

std::string		&Weapon::getType( void ) {
	return (this->type);
}

void			Weapon::setType( std::string type ) {
	this->type = type;
}

