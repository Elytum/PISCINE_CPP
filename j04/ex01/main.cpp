#include "AWeapon.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

void		test_power_fist( void ) {
	PowerFist		weapon;

	std::cout << weapon << "\t";
	weapon.attack();
}

void		test_plasma_rifle( void ) {
	PlasmaRifle		weapon;

	std::cout << weapon << "\t";
	weapon.attack();
}

void		test_weapon( void ) {
	test_power_fist();
	test_plasma_rifle();
}

void		test_super_mutant( void ) {
	SuperMutant		enemy;

	std::cout << enemy << "\t";
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
}

void		test_red_scorpion( void ) {
	RadScorpion		enemy;

	std::cout << enemy << "\t";
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
	enemy.takeDamage( 42 );
}

void		test_enemy( void ) {
	test_super_mutant();
	test_red_scorpion();
}

int			main( void )
{
	test_weapon();
	test_enemy();
	return (0);
}