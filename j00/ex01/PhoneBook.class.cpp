#include <PhoneBook.class.hpp>
#include <iomanip>

PhoneBook& PhoneBook::operator=(const PhoneBook &copy) {
	this->n = copy.get_n();
	return (*this);
}

PhoneBook::PhoneBook(void) {
	this->n = 0;
}

PhoneBook::PhoneBook(const PhoneBook &copy) {
	(*this) = copy;
}

PhoneBook::~PhoneBook(void) {
}

size_t	PhoneBook::get_n(void) const {
	return (this->n);
}

void	PhoneBook::set_n(const size_t n) {
	this->n = n;
}

void	PhoneBook::add(void) {
	if (this->n < this->max)
	{
		this->contacts[this->n].set(this->n);
		this->n++;
	}
	else
		std::cerr << "Too many contacts, I can't remember everything dude..." << std::endl;
}

void	PhoneBook::search(void) {
	size_t		i = 0;
	Contact		c;
	std::string	input;

	if (this->n > 0)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|     index|first name| last name|  nickname|" << std::endl;
		while (i < this->n)
		{
			this->contacts[i].put_field();
			++i;
		}
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Which one of those contacts do you wish to check : ";
		std::getline (std::cin, input);
		try {
			i = std::stoi(input);
		}
		catch (const std::invalid_argument &ia) {
			std::cerr << "Invalid argument: " << ia.what() << std::endl;
			return ;
		} catch (const std::out_of_range &ia) {
			std::cerr << "Invalid argument: " << ia.what() << std::endl;
			return ;
		}
		if (i >= this->n)
			std::cerr << "Indice out of range." << std::endl;
		else
			std::cout << this->contacts[i];
	}
	else
		std::cerr << "I'm sorry but you have no contacts." << std::endl;
}

int		PhoneBook::full(void) {
	return (this->n > max);
}

