#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{

	public:

		Peon( std::string name );
		Peon( Peon const & cpy );
		~Peon();

		// std::string		getName( void ) const;
		// void			setName( std::string const arg );
		
		// Peon&			operator=(Peon const & arg);
		virtual void	getPolymorphed() const;

	private:

		// std::string				name;
};

// std::ostream &operator<<( std::ostream &flux, const Peon &arg );

#endif