#include "FragTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define FRAGTRAP_CHARACTER_SELECTION_QUOTES	{\
										"Hey everybody ! Check out my package!",\
										"Let's get this party started!",\
										"Glitching weirdness is a term of endearment, right ?",\
										"Recompiling my combat code!",\
										"This time it'll be awesome, I promise !",\
										"Look out everybody ! Things are about to get awesome !"\
									}

#define VAULTHUNTER_QUOTES	{\
								"this time it'll be awesome, I promise !",\
								"hey everybody, check out my package !",\
								"defragmenting !",\
								"recompiling my combat code !",\
								"running the sequencer !",\
								"it's happening... it's happening !",\
								"it's about to get magical !",\
								"what will he do next ?",\
								"things are about to get awesome !",\
								"let's get this party started !",\
								"glitchy weirdness is term of endearment, right ?",\
								"i'm a sexy dinosaur ! Rawr.",\
								"oh god I can't stop !",\
								"it's the only way to stop the voices !",\
								"i am cloaking...",\
								"roses are red... Violets are blue... Wait... How many syllables does that have ?",\
								"mini-trap, pretend you're a Siren !",\
								"aww, I shoulda drawn tattoos on it !",\
								"burn them, my mini-phoenix !",\
								"calm down !",\
								"it's time to phase you suckers out !",\
								"tell me I'm the prettiest !",\
								"to the sky, mini-trap !",\
								"fly mini-trap ! Fly !",\
								"i have two robot arms !",\
								"punch 'em in the face, mini-trap !",\
								"ratattattattatta ! Powpowpowpow ! Powpowpowpow ! Pew-pew-pew !",\
								"score one for the turret-trap !",\
								"i'm going commando !",\
								"boiyoiyoiyoiyoing !",\
								"for you...I commit...seppuku...",\
								"some days, you just can't get rid of an obscure pop-culture reference.",\
								"can I use my magic missile.",\
								"do not look behind my curtain !",\
								"i'm made of magic !",\
								"you can call me Gundalf !",\
								"kill ! Reload ! Kill ! Reload ! KILL ! RELOAD !",\
								"like those guys who made only one song ever.",\
								"all these bullets in just one shot.",\
								"one shot, make it count !",\
								"boogie time !",\
								"lasers !",\
								"psychedellic man !",\
								"everybody, dance time ! Da-da-da-dun-daaa-da-da-da-dun-daaa !",\
								"one for you, one for you, and one for you !",\
								"avast ye scurvy dogs !",\
								"is this really canon ?",\
								"i feel a joke about poop decks coming on !",\
							}

#define FRAGTRAP_MELEE_QUOTES	{\
							"This is why you do your homework !",\
							"Class is now in session.",\
							"Hee Yah !",\
							"Take That."\
						}

#define FRAGTRAP_RANGED_QUOTES	{\
							/****************************/\
							/*			Pistols			*/\
							/****************************/\
							"Shaken, not stirred",\
							"The moon is not enough !",\
							"My name is Trap, Claptrap, 00...Trap.",\
							"I expect you to die !",\
							"I'd do anything for a woman with a gun.",\
							/****************************/\
							/*		    Shotguns		*/\
							/****************************/\
							"In yo' FACE !",\
							"Get ready for some Claptrap face time !",\
							"Chk-chk, BOOM !",\
							"You're listening to 'Short-Range Damage Radio.'",\
							"Up-close and personal.",\
							/****************************/\
							/*		 Assault Rifles		*/\
							/****************************/\
							"Get off my lawn.",\
							"Back in my day...",\
							"At least I still have my teeth.",\
							"Coffee ? Black... like my soul.",\
							"Crazy young whippersnappers...",\
							/****************************/\
							/*		 Sniper Rifles		*/\
							/****************************/\
							"Now you're sorted !",\
							"Snoiped !",\
							"Crack shot !"\
						}

#define FRAGTRAP_HEALING_QUOTES	{\
							"Make my day.",\
							"Gimme your best shot.",\
							"Hit me, baby !",\
							"Feeling lucky, punk ?"\
						}

#define FRAGTRAP_DEATH_QUOTES {\
						"Am I dead ? Are you god ? I'M DEAD I'M DEAD OHMYGOD I'M DEAD !"\
					}

static std::string	random_string(const char **array, size_t size) {
	return (array[rand() & size]);
}

FragTrap::FragTrap( std::string	name ) :	name(name),
											hitPoints (100),
											maxHitPoints (100),
											energyPoints (50),
											maxEnergyPoints (50),
											level (1),
											meleeAttackDamage (20),
											rangedAttackDamage (15),
											armorDamageReduction (5) {
	const char	*quotes[] = FRAGTRAP_CHARACTER_SELECTION_QUOTES;

	std::cout << name << ": " << random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
	(void)level;
	(void)energyPoints;
	(void)maxEnergyPoints;
}

FragTrap::FragTrap( FragTrap const & cpy ) {
	std::cout << cpy.name << ": Duplication requested." << std::endl;
	(*this) = cpy;
}

FragTrap::~FragTrap(void) {
	const char	*quotes[] = FRAGTRAP_DEATH_QUOTES;

	std::cout << random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	FragTrap::operator=(FragTrap const & arg) {
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

std::ostream &operator<<(std::ostream& flux, const FragTrap& arg)  {
	flux << "This is me, " << arg.getName() << " !" << std::endl;
	return (flux);
}


void	FragTrap::rangedAttack(std::string const & target) {
	const char	*quotes[] = FRAGTRAP_RANGED_QUOTES;
	std::cout << "FR4G-TP " << name << " attacks " << target << " at range,"\
				" causing " << rangedAttackDamage << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
	const char	*quotes[] = FRAGTRAP_MELEE_QUOTES;
	std::cout << "FR4G-TP " << name << " attacks " << target << " at melee,"\
				" causing " << meleeAttackDamage << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {

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

void	FragTrap::beRepaired(unsigned int amount) {
	const char	*quotes[] = FRAGTRAP_HEALING_QUOTES;

			//	Max repair
	if (hitPoints + amount > maxHitPoints)
		amount = maxHitPoints - hitPoints;

	std::cout << "FR4G-TP " << name << " is repairing " << amount << " points of damage ! "
				<< random_string(quotes, ARRAY_SIZE(quotes) - 1) << std::endl;

	hitPoints += amount;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	const char	*quotes[] = VAULTHUNTER_QUOTES;

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

std::string		FragTrap::getName( void ) const{
	return (name);
}

unsigned int	FragTrap::getHitPoints( void ) const{
	return (hitPoints);
}

unsigned int	FragTrap::getMaxHitPoints( void ) const{
	return (maxHitPoints);
}

unsigned int	FragTrap::getEnergyPoints( void ) const{
	return (energyPoints);
}

unsigned int	FragTrap::getMaxEnergyPoints( void ) const{
	return (maxEnergyPoints);
}

unsigned int	FragTrap::getLevel( void ) const{
	return (level);
}

unsigned int	FragTrap::getMeleeAttackDamage( void ) const{
	return (meleeAttackDamage);
}

unsigned int	FragTrap::getRangedAttackDamage( void ) const{
	return (rangedAttackDamage);
}

unsigned int	FragTrap::getArmorDamageReduction( void ) const{
	return (armorDamageReduction);
}

