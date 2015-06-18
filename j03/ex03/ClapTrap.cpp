#include "ClapTrap.hpp"
#include <cstring>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define CHARACTER_SELECTION_QUOTES	{\
										"Clap clap !",\
										"Hello world !"\
									}

#define MELEE_QUOTES	{\
							"And here comes my melee attack !"\
						}

#define RANGED_QUOTES	{\
							"And here comes my ranged attack !"\
						}

#define HEALING_QUOTES	{\
							"Melissandre, is that you ?"\
						}

#define DEATH_QUOTES {\
						"What is dead may never die."\
					}

std::string	random_string(const char *array[], size_t size) {
		return (array[rand() % size]);
}

std::string			talk_fn ( std::string const & kind ) {
	static const char			*character_selection[] = CHARACTER_SELECTION_QUOTES;
	static const char			*melee[] = MELEE_QUOTES;
	static const char			*ranged[] = RANGED_QUOTES;
	static const char			*healing[] = HEALING_QUOTES;
	static const char			*death[] = DEATH_QUOTES;

	if (kind == "creation")
		return (random_string(character_selection, ARRAY_SIZE(character_selection)));
	else if (kind == "melee")
		return (random_string(melee, ARRAY_SIZE(melee)));
	else if (kind == "ranged")
		return (random_string(ranged, ARRAY_SIZE(ranged)));
	else if (kind == "healing")
		return (random_string(healing, ARRAY_SIZE(ranged)));
	else if (kind == "death")
		return (random_string(death, ARRAY_SIZE(death)));
	return ("");
}

ClapTrap::ClapTrap( std::string	name ) :	talk(talk_fn),
											name(name),
											hitPoints (100),
											maxHitPoints (100),
											energyPoints (100),
											maxEnergyPoints (100),
											level (1),
											meleeAttackDamage (30),
											rangedAttackDamage (20),
											armorDamageReduction (3) {

	std::cout << name << ": " << talk("creation") << std::endl;
	(void)level;
}

ClapTrap::ClapTrap( ClapTrap const & cpy ) : talk(talk_fn) {
	std::cout << cpy.name << ": Duplication requested." << std::endl;
	(*this) = cpy;
}

ClapTrap::~ClapTrap(void) {

	std::cout << talk("death") << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & arg) {
	std::cout << "And here's my new assignement !" << std::endl;

	talk = arg.talk;
	name = arg.getName();
	hitPoints = arg.getHitPoints();
	maxHitPoints = arg.getMaxHitPoints();
	energyPoints = arg.getEnergyPoints();
	maxEnergyPoints = arg.getMaxEnergyPoints();
	level = arg.getLevel();
	meleeAttackDamage = arg.getMeleeAttackDamage();
	rangedAttackDamage = arg.getRangedAttackDamage();
	armorDamageReduction = arg.getArmorDamageReduction();
	return (*this);
}

std::ostream &operator<<(std::ostream& flux, const ClapTrap& arg)  {
	flux << "This is me, " << arg.getName() << " !" << std::endl;
	return (flux);
}


void	ClapTrap::rangedAttack(std::string const & target) {

	std::cout << "FR4G-TP " << name << " attacks " << target << " at range,"\
				" causing " << rangedAttackDamage << " points of damage ! "
				<< talk("ranged") << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) {

	std::cout << "FR4G-TP " << name << " attacks " << target << " at melee,"\
				" causing " << meleeAttackDamage << " points of damage ! "
				<< talk("melee") << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

			//	Armor reduction
	if (armorDamageReduction > amount)
		amount = 0;
	else
		amount -= armorDamageReduction;

			//	Max taken damages
	if (amount > hitPoints)
		amount = hitPoints;

	std::cout << "FR4G-TP " << name << " is taking " << amount
				<< " points of damage !" << std::endl;

	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {

			//	Max repair
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "FR4G-TP " << name << " repaired " << amount << " points of damage ! "
				<< talk("healing") << std::endl;

	hitPoints += amount;
}

std::string		ClapTrap::getName( void ) const{
	return (name);
}

unsigned int	ClapTrap::getHitPoints( void ) const{
	return (hitPoints);
}

unsigned int	ClapTrap::getMaxHitPoints( void ) const{
	return (maxHitPoints);
}

unsigned int	ClapTrap::getEnergyPoints( void ) const{
	return (energyPoints);
}

unsigned int	ClapTrap::getMaxEnergyPoints( void ) const{
	return (maxEnergyPoints);
}

unsigned int	ClapTrap::getLevel( void ) const{
	return (level);
}

unsigned int	ClapTrap::getMeleeAttackDamage( void ) const{
	return (meleeAttackDamage);
}

unsigned int	ClapTrap::getRangedAttackDamage( void ) const{
	return (rangedAttackDamage);
}

unsigned int	ClapTrap::getArmorDamageReduction( void ) const{
	return (armorDamageReduction);
}

