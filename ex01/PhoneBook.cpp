#include "PhoneBook.class.hpp"

PhoneBook& PhoneBook::operator=(const PhoneBook &copy) {
	this->n = copy.get_n();
	return (*this);
}

PhoneBook::PhoneBook(void) {
	this->n = 0;
	std::cout << "In" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &copy)
{
	(*this) = copy;
}

PhoneBook::~PhoneBook(void) {
}

int		PhoneBook::get_n(void) const {
	return (this->n);
}

void	PhoneBook::set_n(const int n) {
	this->n = n;
}

void	PhoneBook::add(void) {
	this->contacts[this->n].set(this->n);
	this->n++;
}

void	PhoneBook::search(void) {
	size_t		i = 0;
	Contact		c;

	std::cout << "   index  |first name|last  name| nickname" << std::endl;
	while (i < this->n)
	{
		this->contacts[i].put_field();
		++i;
	}
	std::cin >> i;
	std::cout << "I = : " << i << std::endl;
}

int		PhoneBook::full(void) {
	return (this->n > max);
}

