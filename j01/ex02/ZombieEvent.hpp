#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <stdlib.h>
#include <time.h>

class ZombieEvent {


public:

	typedef ZombieEvent	t;

	ZombieEvent( void );
	~ZombieEvent( void );

	void					setZombieType( std::string type );
	Zombie					*newZombie( std::string name ) const;
	static std::string		randomName( void );
	void					randomChump( void ) const;

private:
	std::string			type;
};

#endif