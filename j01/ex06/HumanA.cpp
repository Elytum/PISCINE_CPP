#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {
}

HumanA::~HumanA( void ) {
}

void	HumanA::attack() {
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
