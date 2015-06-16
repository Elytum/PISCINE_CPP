#include <PhoneBook.hpp>
#include <Contact.hpp>

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
			std::cout << "Error with input" << std::endl;
			break;
		}
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else
			std::cout << "Unknown command : '" << input << "' use ADD, SEARCH or EXIT instead." << std::endl;
	}
	return (0);
}
