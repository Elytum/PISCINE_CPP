#include <iostream>

#define NO_ARG "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"
#define IS_LOWER(l) (l >= 'a' && l <= 'z')
#define LOWER_TO_UPPER(l) (l - 'a' + 'A')
#define TO_UPPER(l) (IS_LOWER(l) ? LOWER_TO_UPPER(l) : l)

int			main(int ac, char **av)
{
	size_t		pos;
	char		*ptr;

	if (ac == 1)
		std::cout << NO_ARG;
	else
	{
		pos = 0;
		while (--ac)
		{
			ptr = av[++pos];
			while (*ptr)
			{
				*ptr = TO_UPPER(*ptr);
				++ptr;
			}
			std::cout << (av[pos]);
		}
		std::cout << std::endl;
	}
}
