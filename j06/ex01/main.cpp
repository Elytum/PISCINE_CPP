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
	if (rand() % 2 == 1)
		serialized->n |= 1 << (sizeof(int) * 8 - 1);
	extractRand(serialized->s2);
	extractRand(serialized->s2 + sizeof(int));

																if (DEBUG) {
																	std::string	s1;
																	(s1 = reinterpret_cast<char *>(serialized->s1)).resize(8);
																	std::string	s2;
																	(s2 = reinterpret_cast<char *>(serialized->s2)).resize(8);
																	std::cout	<< "Before:" << std::endl
																				<< "s1: '" << s1 << "'" << std::endl
																				<< "n: '" << serialized->n << "'" << std::endl
																				<< "s2: '" << s2 << "'" << std::endl
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
	deserialized->n = *(reinterpret_cast<int *>(array + 8));
	(deserialized->s2 = randomArray2).resize(8);
	return (deserialized);
}

int		main(void)
{
	Data	*sample = deserialize(serialize());

	if (DEBUG)
		std::cout	<< "After:" << std::endl
					<< "s1: '" << sample->s1 << "'" << std::endl
					<< "n: '" << sample->n << "'" << std::endl
					<< "s2: '" << sample->s2 << "'" << std::endl;
	return (0);
}