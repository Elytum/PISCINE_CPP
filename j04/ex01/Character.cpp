#include "Character.hpp"

Character::Character( void ) :	name("Unknown"), APPoints(0), weapon(0) {
}

Character::Character( std::string const & name ) :	name(name), APPoints(40), weapon(0) {
}

Character::~Character() {

}

void		Character::recoverAP( void ) {
	APPoints += + 10;
	if (APPoints > 40)
		APPoints = 40;
}

void		Character::equip(AWeapon* arg) {
	weapon = arg;
}

void		Character::attack(Enemy* arg) {
	if (weapon) {
		int		cost = weapon->getAPCost();
// std::cout << "\t\t\t\tDebug : " << APPoints << ", " << cost << std::endl;
		if (APPoints > cost) {
			APPoints -= cost;

			std::cout << name << " attacks " << arg->getType() << " with a " << weapon->getName() << std::endl;

			weapon->attack();
			arg->takeDamage(weapon->getDamage());
			if (arg->getHP() <= 0)
				delete arg;
		}
	}
}

std::string		Character::getName( void ) const {
	return (name);
}

int				Character::getAPPoints( void ) const {
	return (APPoints);
}

AWeapon*			Character::getWeapon( void ) const {
	return (weapon);
}

std::ostream	&operator<<(std::ostream& flux, const Character& arg) {
	AWeapon			*weapon;

	if ((weapon = arg.getWeapon()))
	{
		flux	<< arg.getName() << " has "
				<< arg.getAPPoints() << " AP and wields a "
				<< weapon->getName()
			<<  std::endl;	
	} else {
		flux	<< arg.getName() << " has "
				<< arg.getAPPoints() << " and is unarmed "
			<<  std::endl;	
	}
	return (flux);
}
