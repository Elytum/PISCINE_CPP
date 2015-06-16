#include <PhoneBook.hpp>
#include <iomanip>

PhoneBook& PhoneBook::operator=(const PhoneBook &copy) {
	this->n = copy.get_n();
	return (*this);
}

PhoneBook::PhoneBook(void) : n(0) {
}

PhoneBook::PhoneBook(const PhoneBook &copy) {
	(*this) = copy;
}

PhoneBook::~PhoneBook(void) {
}

size_t	PhoneBook::get_n(void) const {
	return (n);
}

void	PhoneBook::set_n(const size_t n) {
	this->n = n;
}

void	PhoneBook::add(void) {
	if (n < max)
	{
		contacts[n].set(n);
		n++;
	}
	else
		std::cout << "Too many contacts, I can't remember everything dude..." << std::endl;
}

void	PhoneBook::search(void) {
	size_t		i = 0;
	Contact		c;
	std::string	input;

	if (n > 0)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|     index|first name| last name|  nickname|" << std::endl;
		while (i < n)
		{
			contacts[i].put_field();
			++i;
		}
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Which one of those contacts do you wish to check : ";
		std::getline (std::cin, input);
		try {
			i = std::stoi(input);
		}
		catch (const std::invalid_argument &ia) {
			std::cout << "Invalid argument: " << ia.what() << std::endl;
			return ;
		} catch (const std::out_of_range &ia) {
			std::cout << "Invalid argument: " << ia.what() << std::endl;
			return ;
		}
		if (i >= n)
			std::cout << "Indice out of range." << std::endl;
		else
			std::cout << contacts[i];
	}
	else
		std::cout << "I'm sorry but you have no contacts." << std::endl;
}

int		PhoneBook::full(void) {
	return (n > max);
}

