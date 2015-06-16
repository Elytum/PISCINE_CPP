#include "Zombie.hpp"

Zombie::Zombie( void ) : name("Nobody"), type("Unknown") {
}

Zombie::Zombie( std::string name, std::string type ) : name(name), type(type) {
}

Zombie::~Zombie( void ) {
}

void	Zombie::announce( void ) const {
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}
