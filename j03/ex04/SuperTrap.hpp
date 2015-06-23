#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <math.h>

class SuperTrap : virtual public ClapTrap, public NinjaTrap, public FragTrap
{
	typedef  std::string (talkAction) (std::string const & target);

	public:

		SuperTrap( std::string name );

		void	ninjaShoebox(std::string const & target);
		void	vaulthunter_dot_exe(std::string const & target);

		using 	FragTrap::rangedAttack;
		using 	NinjaTrap::meleeAttack;

	private:
		talkAction		*talk;

		using	FragTrap::name;
		using 	FragTrap::hitPoints;
		using 	FragTrap::maxHitPoints;
		using 	NinjaTrap::energyPoints;
		using 	NinjaTrap::maxEnergyPoints;
		using 	NinjaTrap::meleeAttackDamage;
		using 	FragTrap::rangedAttackDamage;
		using 	FragTrap::armorDamageReduction;
		using 	FragTrap::level;
};

#endif
