#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int		main(void) {
	PhoneBook	book;
	std::string	str;

	while (!book.full())
	{
		std::getline (std::cin, str);
		if (str == "EXIT")
			break ;
		else if (str == "ADD")
			book.add();
		else if (str == "SEARCH")
			book.search();
		else
			std::cout << "Unknown commant : '" << str << "' use ADD, SEARCH or EXIT instead" << std::endl;
	}
	return (0);
}