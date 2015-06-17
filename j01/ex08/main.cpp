#include "Human.hpp"

int		main(void)
{
	std::string		fact[] = {"Jon", "Snow", "is", "dead"};
	std::string		actions[] = {"melee", "ranged", "intimidate"};
	Human			shell;

	size_t			i = 0;
	while (i < sizeof(fact) / sizeof(*fact))
		shell.action(fact[i++], "Fact");
	i = 0;
	while (i < sizeof(actions) / sizeof(*actions))
		shell.action(actions[i++], "Action");
}
