#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <math.h>

class ScavTrap
{

	public:

		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & cpy );
		~ScavTrap();

		void	operator=( const ScavTrap& cpy );

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(std::string const & target);
		

		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getMaxHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getMaxEnergyPoints( void ) const;
		unsigned int	getLevel( void ) const;
		unsigned int	getMeleeAttackDamage( void ) const;
		unsigned int	getRangedAttackDamage( void ) const;
		unsigned int	getArmorDamageReduction( void ) const;

	private:

		std::string		name;
		unsigned int	hitPoints;
		unsigned int	maxHitPoints;
		unsigned int	energyPoints;
		unsigned int	maxEnergyPoints;
		unsigned int	level;
		unsigned int	meleeAttackDamage;
		unsigned int	rangedAttackDamage;
		unsigned int	armorDamageReduction;
};

std::ostream &operator<<( std::ostream &flux, const ScavTrap &fixed );

#endif
