#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	FragTraptest ( void )
{
	std::cout << "Testing FragTrap: " << std::endl << std::endl;
	FragTrap				subject_one("Unknown");
	FragTrap				subject_two("GladOs");
	FragTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					number_of_vaulthunter = 10;

	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);

	while (number_of_vaulthunter--)
		subject_three.vaulthunter_dot_exe(enemy);

}

void	ScavTraptest ( void )
{
	std::cout << "Testing ScavTrap: " << std::endl << std::endl;
	ScavTrap				subject_one("Unknown");
	ScavTrap				subject_two("GladOs");
	ScavTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					number_of_challengers = 10;

	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);

	while (number_of_challengers--)
		subject_three.challengeNewcomer(enemy);
}

int		main(void)
{
	srand(time(NULL));

	FragTraptest();
	std::cout << "Testing of FragTrap done" << std::endl << std::endl;
	ScavTraptest();
	std::cout << "Testing of ScavTrap done" << std::endl;
	return (0);
}