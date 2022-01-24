#include "Contact.hpp"

Contact::Contact(void) : 
_first_name("EMPTY"), _last_name("EMPTY"),
_nickname("EMPTY"), _phone_number("EMPTY"),
_darkest_secret("EMPTY"){
	return;
}

Contact::~Contact(void){
	return;
}

std::string	Contact::getFirstName(void) const{
	return	_first_name;
}

std::string	Contact::getLastName(void) const{
	return	_last_name;
}

std::string	Contact::getNickname(void) const{
	return	_nickname;
}

std::string	Contact::getPhoneNumber(void) const{
	return	_phone_number;
}

std::string Contact::getDarkestSecret(void) const{
	return	_darkest_secret;
}

void		Contact::setFirstName(std::string first_name) {
	this->_first_name = first_name;
	return;
}

void		Contact::setLastName(std::string last_name) {
	this->_last_name = last_name;
	return;
}

void		Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
	return;
}

void		Contact::setPhoneNumber(std::string phone_number) {
	this->_phone_number = phone_number;
	return;
}

void		Contact::setDarkestSecret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
	return;
}
