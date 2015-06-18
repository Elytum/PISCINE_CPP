#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <math.h>

class FragTrap
{

	public:

		FragTrap( std::string name );
		FragTrap( FragTrap const & cpy );
		~FragTrap();

		void	operator=( const FragTrap& cpy );

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);
		

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

std::ostream &operator<<( std::ostream &flux, const FragTrap &fixed );

#endif
