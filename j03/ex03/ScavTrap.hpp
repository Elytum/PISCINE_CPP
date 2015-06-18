#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <math.h>

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap( std::string name );

		void	challengeNewcomer(std::string const & target);

	private:
		
};

std::ostream &operator<<( std::ostream &flux, const ScavTrap &fixed );

#endif
