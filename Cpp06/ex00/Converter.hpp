#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>

class Converter{
	public:
		Converter(std::string input);
		Converter(Converter const & cpy);
		~Converter(void);

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;

		void	detectConvert(void);

		void	showConvert(char) const;
		void	showConvert(int) const;
		void	showConvert(float) const;
		void	showConvert(double) const;
	
		Converter &	operator=(Converter const & asn);
	private:
		Converter(void);

		std::string	_input;

		bool	_isChar(void) const;
		bool	_isInt(void) const;
		bool	_isFloat(void) const;
		bool	_isDouble(void) const;
		bool	_areDigits(void) const;
};