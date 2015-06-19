#include "Character.hpp"

Character::Character( void ) :	name("Unknown"), APPoints(0), weapon(0) {
}

Character::Character( std::string const & name ) :	name(name), APPoints(40), weapon(0) {
}

Character::~Character() {

}

void		Character::recoverAP( void ) {

}

void		Character::equip(AWeapon* arg) {
	(void)arg;
}

void		Character::attack(Enemy* arg) {
	weapon.attach();
	arg.attack(weapon.getDamage());
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
				<< arg.getAPPoints() << " and a "
				<< weapon->getName()
			<<  std::endl;	
	} else {
		flux	<< arg.getName() << " has "
				<< arg.getAPPoints() << " and is unarmed "
			<<  std::endl;	
	}
	return (flux);
}
