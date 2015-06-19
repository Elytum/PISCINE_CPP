#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer( void ) : name("Unknown"), title("Title") {
	std::cout << name << ", " << title << ", is not born, what did you expect ?" << std::endl;
}

Sorcerer::Sorcerer( std::string name, std::string title ) : name(name), title(title) {
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & cpy ) {
	(*this) = cpy;
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void) {
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string		Sorcerer::getName( void ) const {
	return name;
}

void			Sorcerer::setName( std::string const arg ) {
	name = arg;
}

std::string		Sorcerer::getTitle( void ) const {
	return title;
}

void			Sorcerer::setTitle( std::string const arg ) {
	title = arg;
}

void			Sorcerer::polymorph( Victim const & arg ) const {
	arg.getPolymorphed();
}

Sorcerer&	Sorcerer::operator=(Sorcerer const & arg) {
	name = arg.getName();
	title = arg.getTitle();
	return (*this);
}

std::ostream &operator<<(std::ostream& flux, const Sorcerer& arg)  {
	flux << "I am " << arg.getName() << ", " << arg.getTitle() << ", and I like ponies !" << std::endl;
	return (flux);
}
