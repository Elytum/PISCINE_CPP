#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

std::ostream &operator<<(std::ostream& flux, const Contact& c)  {
    c.print(flux) ;
    return (flux);
}

int		main(void) {
	PhoneBook	book;
	std::string	input;

	while (!book.full())
	{
		std::getline (std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else
			std::cout << "Unknown commant : '" << input << "' use ADD, SEARCH or EXIT instead." << std::endl;
	}
	return (0);
}