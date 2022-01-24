#pragma once
#include <string>

class Contact{
	public:
		typedef std::string string;

		Contact(void);
		~Contact(void);

		string getFirstName(void) const;
		string getLastName(void) const;
		string getNickname(void) const;
		string	getPhoneNumber(void) const;
		string	getDarkestSecret(void) const;

		void	setFirstName(string first_name);
		void	setLastName(string last_name);
		void	setNickname(string nickname);
		void	setPhoneNumber(string phone_number);
		void	setDarkestSecret(string darkest_secret);
	private:
		string	_first_name;
		string _last_name;
		string _nickname;
		string	_phone_number;
		string	_darkest_secret;
};
