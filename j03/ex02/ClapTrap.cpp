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
						"What is dead may never die.",\
					}

static size_t						array_size(const std::string array[]) {
	size_t					size = 0;

	std::cout << "Calculating array size" << std::endl;
	while (!array[size].empty()) {
		std::cout << "Array_size: " << array[size] << std::endl;
		size++;
	}
	return (size);
}

static const std::string	random_string(const std::string array[]) {
		return (array[rand() % (array_size(array))]);
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
	const std::string	quotes[] = CLAPTRAP_CHARACTER_SELECTION_QUOTES;

	std::cout << name << ": " << random_string(quotes) << std::endl;
	(void)level;
	(void)energyPoints;
	(void)maxEnergyPoints;
}

ClapTrap::ClapTrap( ClapTrap const & cpy ) {
	std::cout << cpy.name << ": Duplication requested." << std::endl;
	(*this) = cpy;
}

ClapTrap::~ClapTrap(void) {

	std::cout << random_string(deathQuotes) << std::endl;
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
				<< random_string(rangedQuotes) << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) {

	std::cout << "FR4G-TP " << name << " attacks " << target << " at melee,"\
				" causing " << meleeAttackDamage << " points of damage ! "
				<< random_string(meleeQuotes) << std::endl;
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

	std::cout << "\t\tBeginning repair" << std::endl;
			//	Max repair
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "\t\tOutputting repair" << std::endl;
	// std::cout << "Len: " << array_size(rangedQuotes) << std::endl;

	std::cout << "FR4G-TP " << name << " is repairing " << amount << " points of damage ! "
				<< "" << std::endl;

	std::cout << "\t\tAdding repair" << std::endl;

	hitPoints += amount;

	std::cout << "\t\tEnding repair" << std::endl;
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

