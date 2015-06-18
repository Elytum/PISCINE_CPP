#include "ScavTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define SCAVTRAP_CHARACTER_SELECTION_QUOTES	{ "It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !", "Halt, moon citizen ! I've been chosen to stand out here -- far, far away from everyone else -- to guard the main gate to the old communications facility. It's a VERY important duty, as I'm not to let ANYONE in through here ! Unless, of course, you're here as fresh meat for the recruitment grinder !"}

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

static std::string	random_string(const char *array[], size_t size) {
		return (array[rand() & size]);
}

ScavTrap::ScavTrap( std::string	name ) :	ClapTrap(name) {

	std::cout << name << ": " << "INIT" << std::endl;
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

const std::string		ScavTrap::talk ( std::string const & kind ) const {
	static const char		*character_selection[] = SCAVTRAP_CHARACTER_SELECTION_QUOTES;
	static const char		*melee[] = SCAVTRAP_MELEE_QUOTES;
	static const char		*ranged[] = SCAVTRAP_RANGED_QUOTES;
	static const char		*healing[] = SCAVTRAP_HEALING_QUOTES;
	static const char		*death[] = SCAVTRAP_DEATH_QUOTES;

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
	return ("");
	(void)kind;
}
