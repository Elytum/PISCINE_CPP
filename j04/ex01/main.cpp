#include "AWeapon.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#include "Character.hpp"

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