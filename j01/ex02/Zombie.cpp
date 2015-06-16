#include "Zombie.hpp"

Zombie::Zombie( void ) {
	this->name = "Nobody";
	this->type = "Unknown";
}

Zombie::Zombie( std::string name, std::string type ) {
	this->name = name;
	this->type = type;
}

Zombie::~Zombie( void ) {
}

void	Zombie::announce( void ) const {
	std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}
