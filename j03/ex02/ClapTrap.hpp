#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <math.h>

class ClapTrap
{

	public:

		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & cpy );
		~ClapTrap();

		void	operator=( const ClapTrap& cpy );

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

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


	protected:

		std::string		name;
		unsigned int	hitPoints;
		unsigned int	maxHitPoints;
		unsigned int	energyPoints;
		unsigned int	maxEnergyPoints;
		unsigned int	level;
		unsigned int	meleeAttackDamage;
		unsigned int	rangedAttackDamage;
		unsigned int	armorDamageReduction;

		const std::string		&characterSelectionQuotes;
		const std::string		&specialQuotes;
		const std::string		&meleeQuotes;
		const std::string		&rangedQuotes;
		const std::string		&healingQuotes;
		const std::string		&deathQuotes;
};

std::ostream &operator<<( std::ostream &flux, const ClapTrap &fixed );

#endif
