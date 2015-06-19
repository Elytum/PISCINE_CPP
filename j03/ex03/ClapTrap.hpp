#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <math.h>


class ClapTrap
{
	typedef  std::string (talkAction) (std::string const & target);

	public:

		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & cpy );
		~ClapTrap();

		ClapTrap&	operator=( const ClapTrap& cpy );

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

		talkAction		*talk;

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

std::ostream &operator<<( std::ostream &flux, const ClapTrap &fixed );


#endif

std::string	random_string(const char *array[], size_t size);