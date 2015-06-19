#include <iostream>
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main( void )
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	// vlc->push(bob);
	// vlc->push(jim);
	// for (int i = 0; i < vlc->getCount(); ++i)
	// {
		ISpaceMarine* cur = bob;//ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	// }
	delete vlc;

	return 0;
	(void)bob;
	(void)jim;
	(void)vlc;
}