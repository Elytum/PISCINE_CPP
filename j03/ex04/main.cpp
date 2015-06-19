#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

void	FragTraptest ( void )
{
	std::cout << "Testing FragTrap:" << std::endl;
	FragTrap				subject_one("Unknown");
	FragTrap				subject_two("GladOs");
	FragTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					i = 10;

	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);
	std::cout << subject_one << std::endl;

	while (i--)
		subject_three.vaulthunter_dot_exe(enemy);

}

void	ScavTraptest ( void )
{
	std::cout << "Testing ScavTrap:" << std::endl;
	ScavTrap				subject_one("Unknown");
	ScavTrap				subject_two("GladOs");
	ScavTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					i = 10;

	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);
	std::cout << subject_two << std::endl;

	while (i--)
		subject_three.challengeNewcomer(enemy);
}

void	NinjaTraptest ( void )
{
	std::cout << "Testing NinjaTrap:" << std::endl;
	NinjaTrap				subject_one("Unknown");
	NinjaTrap				subject_two("GladOs");
	NinjaTrap				subject_three = subject_two;
	const std::string		enemy = "Elytum";
	size_t					i = 10;

	subject_one.rangedAttack(enemy);
	subject_two.meleeAttack(enemy);
	subject_three.takeDamage(50);
	subject_three.takeDamage(60);
	subject_three.beRepaired(42);
	subject_three.beRepaired(10000);
	std::cout << subject_two << std::endl;

	while (i--)
		subject_three.ninjaShoebox(enemy);
}

int		main(void)
{
	srand(time(NULL));

	FragTraptest();
	std::cout << "Testing of FragTrap done" << std::endl << std::endl;
	ScavTraptest();
	std::cout << "Testing of ScavTrap done" << std::endl << std::endl;;
	NinjaTraptest();
	std::cout << "Testing of NinjaTrap done" << std::endl;
	return (0);
}