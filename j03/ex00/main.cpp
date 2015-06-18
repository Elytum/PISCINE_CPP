#include "FragTrap.hpp"

int		main(void)
{
	srand(time(NULL));

	FragTrap				subject_one("Unknown");
	FragTrap				subject_two("GladOs");
	FragTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					number_of_vaulthunter = 10;

	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);

	while (number_of_vaulthunter--)
		subject_three.vaulthunter_dot_exe(enemy);
	return (0);
}