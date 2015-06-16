#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) {
	this->size = n;
	this->horde = new Zombie[this->size];
}

ZombieHorde::~ZombieHorde( void ) {
	delete [] this->horde;
}

void	ZombieHorde::announce( void ) const {
	int	i;

	i = 0;
	while (i < this->size) {
		this->horde[i++].announce();
	}
}
