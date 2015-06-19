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

		virtual void	getPolymorphed() const;

	private:

		Peon ( void );
};

#endif