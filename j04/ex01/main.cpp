#include "AWeapon.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#include "Character.hpp"

// void		test_power_fist( void ) {
// 	PowerFist		weapon;

// 	std::cout << weapon << "\t";
// 	weapon.attack();
// }

// void		test_plasma_rifle( void ) {
// 	PlasmaRifle		weapon;

// 	std::cout << weapon << "\t";
// 	weapon.attack();
// }

// void		test_weapon( void ) {
// 	test_power_fist();
// 	test_plasma_rifle();
// }

// void		test_super_mutant( void ) {
// 	SuperMutant		enemy;

// 	std::cout << enemy << "\t";
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// }

// void		test_red_scorpion( void ) {
// 	RadScorpion		enemy;

// 	std::cout << enemy << "\t";
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// 	enemy.takeDamage( 42 );
// }

// void		test_enemy( void ) {
// 	test_super_mutant();
// 	test_red_scorpion();
// }

// int			main( void )
// {
// 	test_weapon();
// 	test_enemy();
// 	return (0);
// }

int main()
{
	Character* zaz = new Character("zaz");
std::cout << "\tShould display : \"zaz has 40 AP and is unarmed\"" << std::endl;
	std::cout << *zaz;
std::cout << "\tShould display : \"* click click click *\"" << std::endl;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
std::cout << "\tShould display : \"zaz has 40 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;
	zaz->equip(pf);
std::cout	<< "\tzaz attacks RadScorpion with a Power Fist\"" << std::endl
			<< "\t\"* pschhh... SBAM! *\"" << std::endl;
	zaz->attack(b);

std::cout << "\tShould display : \"zaz has 32 AP and wields a Power Fist\"" << std::endl;
	std::cout << *zaz;
	zaz->equip(pr);
std::cout << "\tShould display : \"zaz has 32 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;
std::cout	<< "\tzaz attacks RadScorpion with a Plasma Rifle\"" << std::endl
			<< "\t\"* piouuu piouuu piouuu *\"" << std::endl;
	zaz->attack(b);

std::cout << "\tShould display : \"zaz has 27 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;
std::cout	<< "\tShould display : \"zaz attacks RadScorpion with a Plasma Rifle\"" << std::endl
			<< "\t\"* piouuu piouuu piouuu *\"" << std::endl
			<< "\t\"* SPROTCH *\"" << std::endl;
	zaz->attack(b);
	std::cout << "\tzaz has 22 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;
	return 0;
}