#include "ClapTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define CLAPTRAP_CHARACTER_SELECTION_QUOTES	{\
										"Clap clap !",\
										"Hello world !"\
									}

#define CLAPTRAP_MELEE_QUOTES	{\
							"And here comes my melee attack !"\
						}

#define CLAPTRAP_RANGED_QUOTES	{\
							"And here comes my ranged attack !"\
						}

#define CLAPTRAP_HEALING_QUOTES	{\
							"Melissandre, is that you ?"\
						}

#define CLAPTRAP_DEATH_QUOTES {\
						"What is dead may never die."\
					}

static std::string	random_string(const char *array[], size_t size) {
		return (array[rand() & size]);
}

ClapTrap::ClapTrap( std::string	name ) :	name(name),
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


const std::string			ClapTrap::talk ( std::string const & kind ) const{
	static const char			*character_selection[] = CLAPTRAP_CHARACTER_SELECTION_QUOTES;
	static const char			*melee[] = CLAPTRAP_MELEE_QUOTES;
	static const char			*ranged[] = CLAPTRAP_RANGED_QUOTES;
	static const char			*healing[] = CLAPTRAP_HEALING_QUOTES;
	static const char			*death[] = CLAPTRAP_DEATH_QUOTES;

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

ClapTrap::ClapTrap( ClapTrap const & cpy ) {
	std::cout << cpy.name << ": Duplication requested." << std::endl;
	(*this) = cpy;
}

ClapTrap::~ClapTrap(void) {

	std::cout << talk("death") << std::endl;
}

void	ClapTrap::operator=(ClapTrap const & arg) {
	std::cout << "And here's my new assignement !" << std::endl;
	name = arg.getName();
	hitPoints = arg.getHitPoints();
	maxHitPoints = arg.getMaxHitPoints();
	energyPoints = arg.getEnergyPoints();
	maxEnergyPoints = arg.getMaxEnergyPoints();
	level = arg.getLevel();
	meleeAttackDamage = arg.getMeleeAttackDamage();
	rangedAttackDamage = arg.getRangedAttackDamage();
	armorDamageReduction = arg.getArmorDamageReduction();
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
				<< " points of damage ! " << std::endl;

	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {

			//	Max repair
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "FR4G-TP " << name << talk("healing") << amount << " points of damage ! "
				<< "" << std::endl;

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

