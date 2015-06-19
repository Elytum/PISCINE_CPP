#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:

	public:
		SuperMutant( void );
		~SuperMutant( void );
		virtual void	takeDamage( int );
};

#endif