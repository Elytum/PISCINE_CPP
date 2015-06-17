#include "Human.hpp"

#define ARRAY_LEN(array) (sizeof(array) / sizeof(*array))

typedef  void (Human::*HumanActions) (std::string const & target);

void Human::meleeAttack(std::string const & target) {
	std::cout << "An human is attacking " << target << " with his sword." << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "An human is attacking " << target << " with his bow." << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "An human is shouting at " << target << ", he seems intimidated." << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	const HumanActions 	actions[] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	const std::string	names[] = {"melee", "ranged", "intimidate"};

	size_t				i = std::find(names, names + ARRAY_LEN(names), action_name) - names;

	if (i != ARRAY_LEN(names))
		(this->*(actions[i]))(target);
}
