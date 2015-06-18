#include "ScavTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define SCAVTRAP_CHARACTER_SELECTION_QUOTES	{\
										"It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !",\
										"Halt, moon citizen ! I've been chosen to stand out here -- far, far away from everyone else -- to guard the main gate to the old communications facility. It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !"\
									}

#define SCAVTRAP_CHALLENGING_QUOTES	{\
							"You wan't a challenge ? Go attach zaz to a tree !",\
							"Go feed the troll !",\
							"Lick your elbow !",\
							"Watch season 9 of srubs !",\
							"Wait for season 6 of Game of Thrones !",\
							"Survive GladOs !"\
						}

#define SCAVTRAP_MELEE_QUOTES	{\
							"See ? I'm like Clank with his big... Wrench"\
						}

#define SCAVTRAP_RANGED_QUOTES	{\
							"And here comes a grenade for table four !"\
						}

#define SCAVTRAP_HEALING_QUOTES	{\
							"You're never gonna kill me !"\
						}

#define SCAVTRAP_DEATH_QUOTES {\
						"Life... Don't talk to me about life...",\
					}

static std::string	random_string(const char **array, size_t size) {
		return (array[rand() & size]);
}

ScavTrap::ScavTrap( std::string	name ) :	name(name),
											hitPoints (100),
											maxHitPoints (100),
											energyPoints (100),
											maxEnergyPoints (100),
											level (1),
											meleeAttackDamage (30),
											rangedAttackDamage (20),
											armorDamageReduction (3) {
	const char	*quotes[] = SCAVTRAP_CHARACTER_SELECTION_QUOTES;

	std::cout << name << ": " << random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
	(void)level;
	(void)energyPoints;
	(void)maxEnergyPoints;
}

ScavTrap::ScavTrap( ScavTrap const & cpy ) {
	std::cout << cpy.name << ": Duplication requested." << std::endl;
	(*this) = cpy;
}

ScavTrap::~ScavTrap(void) {
	const char	*quotes[] = SCAVTRAP_DEATH_QUOTES;

	std::cout << random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	ScavTrap::operator=(ScavTrap const & arg) {
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

std::ostream &operator<<(std::ostream& flux, const ScavTrap& arg)  {
	flux << "This is me, " << arg.getName() << " !" << std::endl;
	return (flux);
}


void	ScavTrap::rangedAttack(std::string const & target) {
	const char	*quotes[] = SCAVTRAP_RANGED_QUOTES;
	std::cout << "FR4G-TP " << name << " attacks " << target << " at range,"\
				" causing " << rangedAttackDamage << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	const char	*quotes[] = SCAVTRAP_MELEE_QUOTES;
	std::cout << "FR4G-TP " << name << " attacks " << target << " at melee,"\
				" causing " << meleeAttackDamage << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {

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

void	ScavTrap::beRepaired(unsigned int amount) {
	const char	*quotes[] = SCAVTRAP_HEALING_QUOTES;

			//	Max repair
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "FR4G-TP " << name << " is repairing " << amount << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;

	hitPoints += amount;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {
	const char	*quotes[] = SCAVTRAP_CHALLENGING_QUOTES;

	if (energyPoints < 25)
		std::cout << name <<	": Like my old buddy used to say : \""\
								"You must construct additional pylons\"."
					<< std::endl;
	else {
		std::cout << name << ": Hey " << target << ", "\
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
		energyPoints -= 25;
	}
}

std::string		ScavTrap::getName( void ) const{
	return (name);
}

unsigned int	ScavTrap::getHitPoints( void ) const{
	return (hitPoints);
}

unsigned int	ScavTrap::getMaxHitPoints( void ) const{
	return (maxHitPoints);
}

unsigned int	ScavTrap::getEnergyPoints( void ) const{
	return (energyPoints);
}

unsigned int	ScavTrap::getMaxEnergyPoints( void ) const{
	return (maxEnergyPoints);
}

unsigned int	ScavTrap::getLevel( void ) const{
	return (level);
}

unsigned int	ScavTrap::getMeleeAttackDamage( void ) const{
	return (meleeAttackDamage);
}

unsigned int	ScavTrap::getRangedAttackDamage( void ) const{
	return (rangedAttackDamage);
}

unsigned int	ScavTrap::getArmorDamageReduction( void ) const{
	return (armorDamageReduction);
}

