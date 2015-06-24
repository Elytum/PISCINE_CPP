#include <iostream>

#define TABSIZE(t) (sizeof(t) / sizeof(*t))

template <typename T>
void	iter(T *addr, int len, T fun(T)) {

	while (len--)
		fun(*addr++);
}

int		addValue (int value) {
	static int	total = 0;

	std::cout << "Total: " << total << " + " << value << " = ";
	total += value;
	std::cout << total << std::endl;
	return (total);
}

int		main(void)
{
	int		tab[] = {4, 2, 0, 42};

	iter(tab, TABSIZE(tab), addValue);
}