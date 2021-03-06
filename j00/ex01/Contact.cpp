#include <Contact.hpp>
#include <iomanip>
#define MAXWIDTH 10
#define SEPARATOR " : "

Contact &Contact::operator=(const Contact &copy) {
	first_name = copy.get_first_name();
	last_name = copy.get_last_name();
	nickname = copy.get_nickname();
	login = copy.get_login();
	postal_address = copy.get_postal_address();
	email_address = copy.get_email_address();
	phone_number = copy.get_phone_number();
	birthday_date = copy.get_birthday_date();
	underwear_color = copy.get_underwear_color();
	darkest_secret = copy.get_darkest_secret();
	return (*this);
}

std::ostream &operator<<(std::ostream& flux, const Contact& c)  {
    c.print(flux) ;
    return (flux);
}

Contact::Contact(void) : first_name(std::string()), last_name(std::string()),
						nickname(std::string()), login(std::string()),
						postal_address(std::string()), email_address(std::string()),
						phone_number(std::string()), birthday_date(std::string()),
						underwear_color(std::string()), darkest_secret(std::string()) {
}

Contact::Contact(const Contact &copy) {
	(*this) = copy;
}

Contact::~Contact(void) {
}

void			Contact::print(void) const {
	print(std::cout);
}

void			Contact::print(std::ostream &flux) const {
	flux << "First name" << SEPARATOR << first_name << std::endl
				<< "Last name" << SEPARATOR << last_name << std::endl
				<< "Nickname" << SEPARATOR << nickname << std::endl
				<< "login" << SEPARATOR << login << std::endl
				<< "Postal address" << SEPARATOR << postal_address << std::endl
				<< "Email address" << SEPARATOR << email_address << std::endl
				<< "Phone number" << SEPARATOR << phone_number << std::endl
				<< "Birthday date" << SEPARATOR << birthday_date << std::endl
				<< "Favorite meal" << SEPARATOR << favorite_meal << std::endl
				<< "Underwear color" << SEPARATOR << underwear_color << std::endl
				<< "Darkest secret" << SEPARATOR << darkest_secret << std::endl;
}

std::string			Contact::format_string(std::string src) const {
	std::string		str = src;

	if (src.size() <= 10)
		return (str);
	str[9] = '.';
	str.resize(10);
	return(str);
}

void			Contact::put_field(void) const {
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout	<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << i
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(first_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(last_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(nickname)
				<< "|" << std::endl;
}

//			Getters

size_t			Contact::get_i(void) const {
	return (i);
}

std::string		Contact::get_first_name(void) const {
	return (first_name);
}

std::string		Contact::get_last_name(void) const {
	return (last_name);
}

std::string		Contact::get_nickname(void) const {
	return (nickname);
}

std::string		Contact::get_login(void) const {
	return (login);
}

std::string		Contact::get_postal_address(void) const {
	return (postal_address);
}

std::string		Contact::get_email_address(void) const {
	return (email_address);
}

std::string		Contact::get_phone_number(void) const {
	return (phone_number);
}

std::string		Contact::get_birthday_date(void) const {
	return (birthday_date);
}

std::string		Contact::get_underwear_color(void) const {
	return (underwear_color);
}

std::string		Contact::get_darkest_secret(void) const {
	return (darkest_secret);
}


//			Setters

void		Contact::set(const size_t i) {
	this->i = i;
	std::cout << "First name : ";
	std::getline (std::cin, first_name);
	std::cout << "Last name : ";
	std::getline (std::cin, last_name);
	std::cout << "Nick name : ";
	std::getline (std::cin, nickname);
	std::cout << "Login : ";
	std::getline (std::cin, login);
	std::cout << "Postal address : ";
	std::getline (std::cin, postal_address);
	std::cout << "Email address : ";
	std::getline (std::cin, email_address);
	std::cout << "Phone number: ";
	std::getline (std::cin, phone_number);
	std::cout << "Birthday date : ";
	std::getline (std::cin, birthday_date);
	std::cout << "Favorite meal : ";
	std::getline (std::cin, favorite_meal);
	std::cout << "Underwear color : ";
	std::getline (std::cin, underwear_color);
	std::cout << "Darkest secret : ";
	std::getline (std::cin, darkest_secret);
}

void		Contact::set_i(const size_t i) {
	this->i = i;
}

void		Contact::set_first_name(const std::string first_name) {
	this->first_name = first_name;
}

void		Contact::set_last_name(const std::string last_name) {
	this->last_name = last_name;
}

void		Contact::set_nickname(const std::string nickname) {
	this->nickname = nickname;
}

void		Contact::set_login(const std::string login) {
	this->login = login;
}

void		Contact::set_postal_address(const std::string postal_address) {
	this->postal_address = postal_address;
}

void		Contact::set_email_address(const std::string email_address) {
	this->email_address = email_address;
}

void		Contact::set_phone_number(const std::string phone_number) {
	this->phone_number = phone_number;
}

void		Contact::set_birthday_date(const std::string birthday_date) {
	this->birthday_date = birthday_date;
}

void		Contact::set_underwear_color(const std::string underwear_color) {
	this->underwear_color = underwear_color;
}

void		Contact::set_darkest_secret(const std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}