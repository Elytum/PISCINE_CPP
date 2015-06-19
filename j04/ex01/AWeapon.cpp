#include "AWeapon.hpp"

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) :
								name(name), APCost(apcost), damage(damage) {
}

AWeapon::AWeapon( void ) : name("Unknown"), APCost(0), damage(0) {
}


AWeapon::AWeapon( AWeapon const & cpy ) {
	(*this) = cpy;
}

AWeapon::~AWeapon(void) {
}

std::string		AWeapon::getName() const{
	return (name);
}

int				AWeapon::getAPCost() const{
	return (APCost);
}

int				AWeapon::getDamage() const{
	return (damage);
}

AWeapon&		AWeapon::operator=(AWeapon const & arg) {
	name = arg.getName();
	APCost = arg.getAPCost();
	damage = arg.getDamage();
	return (*this);
}

std::ostream	&operator<<(std::ostream& flux, const AWeapon& arg) {
	flux	<< "This is a \"" << arg.getName()
			<< "\", it deals " << arg.getDamage()
			<< ", for an AP cost of " << arg.getAPCost()
		<< std::endl;
	return (flux);
}
