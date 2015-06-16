#include "Pony.hpp"
#include <iostream>

Pony::Pony( void ) {
	std::cout << "Just created a pony." << std::endl;
}

Pony::~Pony( void ) {
	std::cout << "Just destructed a pony." << std::endl;
	this->die();
}

Pony		Pony::ponyOnTheStack( void ) {
	Pony	ponyta = Pony();

	ponyta.name = "Ponyta";
	ponyta.image = PONYTA;
	ponyta.death = PONYTA_DIED;
	std::cout << ponyta;
	return (ponyta);
}

Pony		*Pony::ponyOnTheHeap( void ) {
	Pony	*unicorn = new Pony();

	unicorn->name = "Unicorn";
	unicorn->image = UNICORN;
	unicorn->death = UNICORN_DIED;
	std::cout << (*unicorn);
	return (unicorn);
}

void		Pony::print(void) const {
	print(std::cout);
}

void		Pony::print(std::ostream &flux) const {
	flux << "A poney, just born, said his name : \"" << this->name << "\", what a surprise !" << std::endl;
}

void		Pony::show(void) const {
	std::cout << this->image << std::endl;
}

void		Pony::die(void) const {
	std::cout << this->death << std::endl;
}

std::ostream &operator<<(std::ostream& flux, const Pony& p)  {
	p.print(flux);
	return (flux);
}