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
	Character* zaz = new Character("zaz");		//												Create zaz
std::cout << "\tShould display : \"zaz has 40 AP and is unarmed\"" << std::endl;
	std::cout << *zaz;							// zaz has 40 AP and is unarmed
std::cout << "\tShould display : \"* click click click *\"" << std::endl;
	Enemy* b = new RadScorpion();				// * click click click *
	AWeapon* pr = new PlasmaRifle();			//												Create Plasma
	AWeapon* pf = new PowerFist();				//												Create Fist

	zaz->equip(pr);								//												Equip Plasma
std::cout << "\tShould display : \"zaz has 40 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;							// zaz has 40 AP and wields a Plasma Rifle
	zaz->equip(pf);								//												Equip Fist
std::cout	<< "\tzaz attacks RadScorpion with a Power Fist\"" << std::endl
			<< "\t\"* pschhh... SBAM! *\"" << std::endl;
	zaz->attack(b);								// zaz attacks RadScorpion with a Power Fist
												// * pschhh... SBAM! *
std::cout << "\tShould display : \"zaz has 32 AP and wields a Power Fist\"" << std::endl;
	std::cout << *zaz;							// zaz has 32 AP and wields a Power Fist
	zaz->equip(pr);								//
std::cout << "\tShould display : \"zaz has 32 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;							// zaz has 32 AP and wields a Plasma Rifle
std::cout	<< "\tzaz attacks RadScorpion with a Plasma Rifle\"" << std::endl
			<< "\t\"* piouuu piouuu piouuu *\"" << std::endl;
	zaz->attack(b);								// zaz attacks RadScorpion with a Plasma Rifle
												// * piouuu piouuu piouuu *
std::cout << "\tShould display : \"zaz has 27 AP and wields a Plasma Rifle\"" << std::endl;
	std::cout << *zaz;							// zaz has 27 AP and wields a Plasma Rifle
std::cout << "\tShould display : \"zaz attacks RadScorpion with a Plasma Rifle\"" << std::endl;
	zaz->attack(b);								// zaz attacks RadScorpion with a Plasma Rifle
std::cout << "\tShould display : \"* piouuu piouuu piouuu *\"" << std::endl;
												// * piouuu piouuu piouuu *
std::cout << "\tShould display : \"* SPROTCH *\"" << std::endl;
	std::cout << *zaz;							// * SPROTCH *
	return 0;
}