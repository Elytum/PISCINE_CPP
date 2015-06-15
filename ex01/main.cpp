#include <PhoneBook.class.hpp>
#include <Contact.class.hpp>

std::ostream &operator<<(std::ostream& flux, const Contact& c)  {
    c.print(flux) ;
    return (flux);
}

int		main(void) {
	PhoneBook	book;
	std::string	input;

	while (!book.full())
	{
		std::cout << "Please type your command (ADD, SEARCH or EXIT) : ";
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			std::cout << "EOF reached" << std::endl;
			break;
		} else if (std::cin.bad()) {
			std::cerr << "Error with input" << std::endl;
			break;
		}
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else
			std::cerr << "Unknown commant : '" << input << "' use ADD, SEARCH or EXIT instead." << std::endl;
	}
	return (0);
}
