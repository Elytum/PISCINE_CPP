#include "Contact.class.hpp"
#include <iomanip>
#define MAXWIDTH 10

Contact& Contact::operator=(const Contact &copy) {
	this->first_name = copy.get_first_name();
	this->last_name = copy.get_last_name();
	this->nickname = copy.get_nickname();
	this->login = copy.get_login();
	this->postal_address = copy.get_postal_address();
	this->email_address = copy.get_email_address();
	this->phone_number = copy.get_phone_number();
	this->birthday_date = copy.get_birthday_date();
	this->underwear_color = copy.get_underwear_color();
	this->darkest_secret = copy.get_darkest_secret();
	return (*this);
}

Contact::Contact(void) {
	this->first_name = std::string();
	this->last_name = std::string();
	this->nickname = std::string();
	this->login = std::string();
	this->postal_address = std::string();
	this->email_address = std::string();
	this->phone_number = std::string();
	this->birthday_date = std::string();
	this->underwear_color = std::string();
	this->darkest_secret = std::string();
}

Contact::Contact(const Contact &copy)
{
	(*this) = copy;
}

Contact::~Contact(void) {
}

void			Contact::print(void) const {
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout	<< std::setw(MAXWIDTH) << std::setfill(' ') << this->i
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->first_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->last_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->nickname)
				<< std::endl;
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
	std::cout	<< std::setw(MAXWIDTH) << std::setfill(' ') << this->i
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->first_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->last_name)
				<< "|" << std::setw(MAXWIDTH) << std::setfill(' ') << format_string(this->nickname)
				<< std::endl;
}

//			Getters

size_t			Contact::get_i(void) const {
	return (this->i);
}

std::string		Contact::get_first_name(void) const {
	return (this->first_name);
}

std::string		Contact::get_last_name(void) const {
	return (this->last_name);
}

std::string		Contact::get_nickname(void) const {
	return (this->nickname);
}

std::string		Contact::get_login(void) const {
	return (this->login);
}

std::string		Contact::get_postal_address(void) const {
	return (this->postal_address);
}

std::string		Contact::get_email_address(void) const {
	return (this->email_address);
}

std::string		Contact::get_phone_number(void) const {
	return (this->phone_number);
}

std::string		Contact::get_birthday_date(void) const {
	return (this->birthday_date);
}

std::string		Contact::get_underwear_color(void) const {
	return (this->underwear_color);
}

std::string		Contact::get_darkest_secret(void) const {
	return (this->darkest_secret);
}


//			Setters

void		Contact::set(const size_t i) {
	this->i = i;
	std::cout << "First name :" << std::endl;
	std::getline (std::cin, this->first_name);
	std::cout << "Last name :" << std::endl;
	std::getline (std::cin, this->last_name);
	std::cout << "Nick name :" << std::endl;
	std::getline (std::cin, this->nickname);
	std::cout << "Login :" << std::endl;
	std::getline (std::cin, this->login);
	std::cout << "Postal address :" << std::endl;
	std::getline (std::cin, this->postal_address);
	std::cout << "Email address :" << std::endl;
	std::getline (std::cin, this->email_address);
	std::cout << "Phone number:" << std::endl;
	std::getline (std::cin, this->phone_number);
	std::cout << "Birthday date :" << std::endl;
	std::getline (std::cin, this->birthday_date);
	std::cout << "Underwear color :" << std::endl;
	std::getline (std::cin, this->underwear_color);
	std::cout << "Darkest secret :" << std::endl;
	std::getline (std::cin, this->darkest_secret);
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