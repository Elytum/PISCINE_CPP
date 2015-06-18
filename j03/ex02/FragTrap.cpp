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

#define FRAGTRAP_VAULTHUNTER_QUOTES	{\
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
						"Am I dead ? Are you god ? I'M DEAD I'M DEAD OHMYGOD I'M DEAD !", "SPAM"\
					}

static std::string	random_string(const std::string array[], size_t size) {
		return (array[rand() & size]);
}

FragTrap::FragTrap( std::string	name ) :	ClapTrap(name) {

	static const std::string myCharacterSelectionQuotes[] = FRAGTRAP_CHARACTER_SELECTION_QUOTES;
	static const std::string mySpecialQuotes[] = FRAGTRAP_VAULTHUNTER_QUOTES;
	static const std::string myMeleeQuotes[] = FRAGTRAP_MELEE_QUOTES;
	static const std::string myRangedQuotes[] = FRAGTRAP_RANGED_QUOTES;
	static const std::string myHealingQuotes[] = FRAGTRAP_HEALING_QUOTES;
	static const std::string myDeathQuotes[] = FRAGTRAP_DEATH_QUOTES;

	characterSelectionQuotes = myCharacterSelectionQuotes;
	specialQuotes = mySpecialQuotes;
	meleeQuotes = myMeleeQuotes;
	rangedQuotes = myRangedQuotes;
	healingQuotes = myHealingQuotes;
	deathQuotes = myDeathQuotes;

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

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {

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
