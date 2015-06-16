#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#define TYPES {"Generic Zombie", "Runner", "Stalker", "Crawler", "Bonies", "Spitters", "Exploders", "Radioactive Zombies"}
#define HORDE_SIZE 100
#define HORDE_MESSAGES 100

void	generate_chump(ZombieEvent *event, size_t quantity)
{
	while (quantity != 0)
	{
		event->randomChump();
		--quantity;
	}
}

void	generate_horde(Zombie *horde[HORDE_SIZE], ZombieEvent *event, size_t quantity, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < quantity)
	{
		if (pos + i >= HORDE_SIZE)
			return ;
		horde[pos + i] = event->newZombie(ZombieEvent::randomName());
		++i;
	}
}

void	talk_horde(Zombie *horde[HORDE_SIZE], size_t quantity)
{
	while (quantity--)
		horde[rand() % HORDE_SIZE]->announce();
}

int main(void)
{
	ZombieEvent	*event = new ZombieEvent();
	Zombie		*horde[HORDE_SIZE];
	size_t		i;

	srand ( time(NULL) );
	generate_chump(event, 42);
	generate_horde(horde, event, HORDE_SIZE, 0);
	talk_horde(horde, 42);
	delete event;
	i = 0;
	while (i < HORDE_SIZE)
		delete horde[i++];
	return (0);
}