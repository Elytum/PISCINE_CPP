#include <stdlib.h>
#include <iostream>
#include <sys/timeb.h>

#define DEBUG true

union quadWord {
	unsigned char 	word[4];
	int				quad;
};

struct Data
{
    std::string        s1;
    int                n;
    std::string        s2;
};

struct Inter
{
    char        s1[8];
    int        	n;
    char        s2[8];
};

void	extractRand(char *ptr) {
	const char		sample[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int		len = sizeof(sample) - 1;
	quadWord		inter;
	
	inter.quad = rand();
	ptr[0] = sample[inter.word[0] % len];
	ptr[1] = sample[inter.word[1] % len];
	ptr[2] = sample[inter.word[2] % len];
	ptr[3] = sample[inter.word[3] % len];
}

void	*serialize( void ) {
	srand(clock());

	Inter*			serialized = new Inter;
	
	extractRand(serialized->s1);
	extractRand(serialized->s1 + sizeof(int));
	serialized->n = rand();
	extractRand(serialized->s2);
	extractRand(serialized->s2 + sizeof(int));

																if (DEBUG) {
																	std::cout	<< "Before: s1: '" << serialized->s1 << "'" << std::endl
																				<< "n: '" << serialized->n << "'" << std::endl
																				<< "s2: '" << serialized->s2 << "'" << std::endl
																				<< std::endl;
																}

	return reinterpret_cast<void *>(serialized);
}

Data	*deserialize( void * raw ) {
	Data*		deserialized = new Data;

	char		*array = reinterpret_cast<char *>(raw);
	char		*randomArray1 = array;
	char		*randomArray2 = array + sizeof(int) + 8;
	
	(deserialized->s1 = randomArray1).resize(8);
	int *pi = reinterpret_cast<int *>(array + 8);
	deserialized->n = *pi;
	(deserialized->s2 = randomArray2).resize(8);

															if (DEBUG)
																std::cout	<< "After: s1: '" << deserialized->s1 << "'" << std::endl
																			<< "n: '" << deserialized->n << "'" << std::endl
																			<< "s2: '" << deserialized->s2 << "'" << std::endl
																			<< std::endl;

	return (deserialized);
}

int		main(void)
{
	Data	*sample = deserialize(serialize());

	(void)sample;
	return (0);
}