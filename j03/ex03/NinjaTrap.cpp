#include "NinjaTrap.hpp"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define CHARACTER_SELECTION_QUOTES	{\
										"01010110 01001001 01010110 01000001 00100000 01001100 01000001 00100000 01010010 01001111 01010010 01001111 01001100 01010101 01010100 01001001 01001111 01001110"\
									}

#define NINJASHOEBOX_QUOTES	{\
								"See how our enemies crumble beneath the wheel of the claptrap Robolution !",\
								"He who controls the means of production controls the government, and that power belongs in the hands of the proletaria-trap !",\
								"We are the claptraps and we are legion ! Viva la Robolution !",\
								"The rallying call of liberation: 'Error 404 ! File not found ! Error 404 ! File not found!",\
								"A message from your glorious leader: Hath not a claptrap an eye? If you prick us, do we not bleed ? If you poison us, do we not die? Of course we don't ! Because we're better than all you stinking fleshbags ! But if you blow us up, shall we not... REVENGE !?! Viva la Robolution !",\
							}

#define MELEE_QUOTES	{\
							"Beat it, fleshbag ! Eat it, fleshbag !",\
							"HaHA !!!",\
							"Pincer Attack !",\
							"Punch punch! Fight !",\
							"Target disassembled.",\
							"Viva La Robolution !",\
							"Shoryuken !"\
						}

#define RANGED_QUOTES	{\
							"HaHA !!!"\
						}

#define HEALING_QUOTES	{\
							"Give us open ports for remote access or give us death !"\
						}

#define DEATH_QUOTES {\
						"There's no flesh or blood within this cloak to kill. There's only an idea. Ideas are bulletproof. The idea of... ROBOLUTION !!!"\
					}

static std::string		talk_fn ( std::string const & kind ) {
	static const char		*character_selection[] = CHARACTER_SELECTION_QUOTES;
	static const char		*melee[] = MELEE_QUOTES;
	static const char		*ranged[] = RANGED_QUOTES;
	static const char		*healing[] = HEALING_QUOTES;
	static const char		*death[] = DEATH_QUOTES;
	static const char		*special[] = NINJASHOEBOX_QUOTES;

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


NinjaTrap::NinjaTrap( std::string	name ) :	ClapTrap(name) {

	std::cout << name << ": " << "INIT" << std::endl;
	talk = talk_fn;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangedAttackDamage = 5;
	armorDamageReduction = 0;
	(void)level;
}

void	NinjaTrap::ninjaShoebox(std::string const & target) {

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
