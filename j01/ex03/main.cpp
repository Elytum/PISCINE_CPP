#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde	horde = ZombieHorde(100);

	horde.announce();
	return (0);
}