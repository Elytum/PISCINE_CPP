#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <stdlib.h>
#include <time.h>

class ZombieEvent {


public:

	ZombieEvent( void );
	~ZombieEvent( void );

	static std::string		randomName( void );
	void					randomChump( void ) const;
	Zombie					*newZombie( std::string name ) const;
	void					setZombieType( std::string type );

private:
	std::string			type;
};

#endif