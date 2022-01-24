#pragma once
#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>


class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		openPhoneBook(void);
	private:
		Contact		_contacts[8];
		int			_first_contact;

		void		_addContact(void);
		void		_printPhoneBook(void);
		void		_selectContact(void);

		Contact*	_getContact(int index);
		void		_increaseIndex(void);
		std::string	_formatOut(std::string out);
		bool		_checkNum(std::string str) const;
		bool		_allNumeric(std::string str) const;
		void		_printContact(int index);
};
