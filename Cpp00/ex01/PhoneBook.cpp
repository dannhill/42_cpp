#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :
_first_contact(0){
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void		PhoneBook::openPhoneBook(void){
	std::string	buffer;

	std::cout << "Welcome to the amazing Phone Book!!!!!!" << std::endl;
	std::cout << "type ADD to add a contact, EXIT to quit the program, or SEARCH to seek existing contact." << std::endl;
	while (true)
	{
		std::cout << "->";
		std::getline(std::cin, buffer);
		if (buffer.compare("ADD") == 0)
			_addContact();
		else if (buffer.compare("SEARCH") == 0)
		{
			_printPhoneBook();
			_selectContact();
		}
		else if (buffer.compare("EXIT") == 0)
		{
			std::cout << "Closing program..." << std::endl;
			return;
		}
		else
		{
			std::cout << "Wrong input: type ADD to add a contact, EXIT to quit the program, or SEARCH to seek existing contact." << std::endl;
		}
	}
	return;
}

void		PhoneBook::_addContact(void){
	std::string	buffer;

	std::cout << "Define new contact..." << std::endl;
	std::cout << "Contact first name: ";
	std::getline(std::cin, buffer);
	this->_contacts[_first_contact].setFirstName(buffer);
	std::cout << "Contact last name: ";
	std::getline(std::cin, buffer);
	this->_contacts[_first_contact].setLastName(buffer);
	std::cout << "Contact nickname: ";
	std::getline(std::cin, buffer);
	this->_contacts[_first_contact].setNickname(buffer);
	while (true)
	{
		std::cout << "Contact phone number: ";
		std::getline(std::cin, buffer);
		if (_allNumeric(buffer))
			break;
		std::cout << "Input must be all numeric." << std::endl;
	}
	this->_contacts[_first_contact].setPhoneNumber(buffer);
	std::cout << "Contact darkest secret: ";
	std::getline(std::cin, buffer);
	this->_contacts[_first_contact].setDarkestSecret(buffer);
	_increaseIndex();

	return;
}

Contact* PhoneBook::_getContact(int index){
	return &_contacts[index];
}

void PhoneBook::_printPhoneBook(void){
	Contact	*c;

	for (int i = 0; i < 8; i++)
	{
		c = _getContact(i);
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _formatOut(c->getFirstName()) << "|";
		std::cout << std::setw(10) << _formatOut(c->getLastName()) << "|";
		std::cout << std::setw(10) << _formatOut(c->getNickname()) << "|";
		std::cout << std::endl;
	}

	return;
}

void PhoneBook::_selectContact(void){
	std::string	buffer;
	int			index;

	while (true)
	{
		std::cout << "Select contact using index: ";
		std::getline(std::cin, buffer);
		std::stringstream	medium(buffer);
		index = 0;
		medium >> index;
		if (!_checkNum(buffer) || index < 0 || index > 7)
		{
			std::cerr << "Error: wrong index (Insert numbers between 0 and 7)" << std::endl;
			continue;
		}
		break;
	}
	_printContact(index);
}

void	PhoneBook::_increaseIndex(void) {
	if (_first_contact < 7)
		_first_contact++;
	else if (_first_contact >= 7)
		_first_contact = 0;
	
	return;
}

void PhoneBook::_printContact(int index){
	Contact* c;

	c = this->_getContact(index);
	std::cout << "First name: " << c->getFirstName() << std::endl;
	std::cout << "Last name: " << c->getLastName() << std::endl;
	std::cout << "Nickname: " << c->getNickname() << std::endl;
	std::cout << "Phone number: " << c->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c->getDarkestSecret() << std::endl;

	return;
}

std::string	PhoneBook::_formatOut(std::string out){
	if (out.length() > 10)
	{
		out.resize(9);
		out.resize(10, '.');
	}

	return out;
}

//checks if a string contains at list a digit
bool	PhoneBook::_checkNum(std::string str) const
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (isdigit(str[i]))
			return true;
	}
	return false;
}

bool	PhoneBook::_allNumeric(std::string str) const{
	for(int i = 0; i < (int)str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
