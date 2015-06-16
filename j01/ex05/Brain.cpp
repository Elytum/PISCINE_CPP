#include "Brain.hpp"
#include <sstream>
#include <string>

Brain::Brain( void ) {
}

Brain::~Brain( void ) {
}

std::string	Brain::identify( void ) const {
	std::stringstream	ss;
	std::string			str;
	size_t				i;

	ss << this;
	str = ss.str();
	i = 2;
	while (i < str.size()) {
		str[i] = toupper(str[i]);
		++i;
	}
	return (str);
}
