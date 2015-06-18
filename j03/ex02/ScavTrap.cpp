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

static std::string	random_string(const std::string array[], size_t size) {
		return (array[rand() & size]);
}

size_t						array_size(const std::string array[]) {
	size_t					size = 0;

	std::cout << "Calculating array size" << std::endl;
	while (!array[size].empty()) {
		std::cout << "Array_size: " << array[size] << std::endl;
		size++;
	}
	return (size);
}

static std::string 	*dup_string_array(const std::string array[])
{
	size_t			i = 0;
	size_t			size = array_size(array);
	std::string		*copied = new std::string[size];

	while (i < size) {
		copied[i] = array[i]; 
		++i;
	}
	return (copied);
}

ScavTrap::ScavTrap( std::string	name ) :	ClapTrap(name) {
	bool	first = true;

	static std::string *myCharacterSelectionQuotes;
	static std::string *mySpecialQuotes;
	static std::string *myMeleeQuotes;
	static std::string *myRangedQuotes;
	static std::string *myHealingQuotes;
	static std::string *myDeathQuotes;

	if (first == true) {

		first = false;

		std::string hCharacterSelectionQuotes[] = SCAVTRAP_CHARACTER_SELECTION_QUOTES;
		std::string hSpecialQuotes[] = SCAVTRAP_CHALLENGING_QUOTES;
		std::string hMeleeQuotes[] = SCAVTRAP_MELEE_QUOTES;
		std::string hRangedQuotes[] = SCAVTRAP_RANGED_QUOTES;
		std::string hHealingQuotes[] = SCAVTRAP_HEALING_QUOTES;
		std::string hDeathQuotes[] = SCAVTRAP_DEATH_QUOTES;

		myCharacterSelectionQuotes = dup_string_array(hCharacterSelectionQuotes);//(hCharacterSelectionQuotes);
		mySpecialQuotes = dup_string_array(hSpecialQuotes);//(hSpecialQuotes);
		myMeleeQuotes = dup_string_array(hMeleeQuotes);//(hMeleeQuotes);
		myRangedQuotes = dup_string_array(hRangedQuotes);//(hRangedQuotes);
		myHealingQuotes = dup_string_array(hHealingQuotes);//(hHealingQuotes);
		myDeathQuotes = dup_string_array(hDeathQuotes);//(hDeathQuotes);

	}

	characterSelectionQuotes = &myCharacterSelectionQuotes;
	specialQuotes = &mySpecialQuotes;
	meleeQuotes = &myMeleeQuotes;
	rangedQuotes = &myRangedQuotes;
	healingQuotes = &myHealingQuotes;
	deathQuotes = &myDeathQuotes;

	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 3;

	std::cout << name << ": " << random_string(myCharacterSelectionQuotes, ARRAY_SIZE(myCharacterSelectionQuotes) - 1) << std::endl;
	(void)level;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {

	if (energyPoints < 25)
		std::cout << name <<	": Like my old buddy used to say : \""\
								"You must construct additional pylons\"."
					<< std::endl;
	else {
		std::cout << name << ": Hey " << target << ", "\
				<< random_string(specialQuotes, ARRAY_SIZE(specialQuotes) - 1) << std::endl;
		energyPoints -= 25;
	}
}
