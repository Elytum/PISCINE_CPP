#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <math.h>

class FragTrap : public ClapTrap
{

	public:

		FragTrap( std::string name );

		void	vaulthunter_dot_exe(std::string const & target);

	private:
		
};

std::ostream &operator<<( std::ostream &flux, const FragTrap &fixed );

#endif
