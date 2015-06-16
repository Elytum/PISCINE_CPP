#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include "zombie.hpp"

class ZombieHorde {


public:

	typedef ZombieHorde	t;

	ZombieHorde( int n );
	~ZombieHorde( void );

	void	announce( void ) const;

private:
	int		size;
	Zombie	*horde;
};

#endif