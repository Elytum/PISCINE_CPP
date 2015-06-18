#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <math.h>

class NinjaTrap : public ClapTrap
{

	public:

		NinjaTrap( std::string name );

		void	ninjaShoebox(std::string const & target);

	private:
		
};

std::ostream &operator<<( std::ostream &flux, const NinjaTrap &fixed );

#endif
