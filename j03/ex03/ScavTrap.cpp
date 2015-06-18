#include "ScavTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define CHARACTER_SELECTION_QUOTES	{ "It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !", "Halt, moon citizen ! I've been chosen to stand out here -- far, far away from everyone else -- to guard the main gate to the old communications facility. It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !"}

#define CHALLENGING_QUOTES	{\
							"You wan't a challenge ? Go attach zaz to a tree !",\
							"Go feed the troll !",\
							"Lick your elbow !",\
							"Watch season 9 of srubs !",\
							"Wait for season 6 of Game of Thrones !",\
							"Survive GladOs !"\
						}

#define MELEE_QUOTES	{\
							"See ? I'm like Clank with his big... Wrench"\
						}

#define RANGED_QUOTES	{\
							"And here comes a grenade for table four !"\
						}

#define HEALING_QUOTES	{\
							"You're never gonna kill me !"\
						}

#define DEATH_QUOTES {\
						"Life... Don't talk to me about life...",\
					}

std::string		talk_fn_scav ( std::string const & kind ) {
	static const char		*character_selection[] = CHARACTER_SELECTION_QUOTES;
	static const char		*melee[] = MELEE_QUOTES;
	static const char		*ranged[] = RANGED_QUOTES;
	static const char		*healing[] = HEALING_QUOTES;
	static const char		*death[] = DEATH_QUOTES;
	static const char		*special[] = CHALLENGING_QUOTES;

	if (kind == "creation")
		return (random_string(character_selection, ARRAY_SIZE(character_selection)));
	else if (kind == "melee")
		return (random_string(melee, ARRAY_SIZE(melee)));
	else if (kind == "ranged")
		return (random_string(ranged, ARRAY_SIZE(ranged)));
	else if (kind == "healing")
		return (random_string(healing, ARRAY_SIZE(healing)));
	else if (kind == "death")
		return (random_string(death, ARRAY_SIZE(death)));
	else if (kind == "special")
		return (random_string(special, ARRAY_SIZE(special)));
	return ("");
}


ScavTrap::ScavTrap( std::string	name ) :	ClapTrap(name) {

	std::cout << name << ": " << "INIT" << std::endl;
	talk = talk_fn_scav;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 12;
	armorDamageReduction = 3;
	(void)level;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {

	if (energyPoints < 25)
		std::cout << name <<	": Like my old buddy used to say : \""\
								"You must construct additional pylons\"."
					<< std::endl;
	else {
		std::cout << name << ": Hey " << target << ", "\
				<< talk("special") << std::endl;
		energyPoints -= 25;
	}
}
