#include "Converter.hpp"

Converter::Converter(std::string input) : _input(input){
	return;
}

Converter::~Converter(void){
	return;
}

Converter::operator char(void) const{
	char	c('a');

	c = static_cast<char>(atoi(_input.c_str()));
	return c;
}

Converter::operator int(void) const{
	int	i(0);

	i = atoi(_input.c_str());
	return i;
}

Converter::operator float(void) const{
	float	f(0.0f);

	f = static_cast<float>(atof(_input.c_str()));
	return f;
}

Converter::operator double(void) const{
	double	d(0.0);

	d = atof(_input.c_str());
	return d;
}

void	Converter::detectConvert(void){
	if (_isChar())
		showConvert(char());
	else if (!_areDigits())
	{
		std::cerr << "Error: digits must appear in argument." << std::endl;
		return;
	}
	else if (_isInt())
		showConvert(int());
	else if (_isFloat())
		showConvert(float());
	else if (_isDouble())
		showConvert(double());
	return;
}

void	Converter::showConvert(char) const{
	char	c('a');

	c = _input[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return;
}

void	Converter::showConvert(int) const{
	int	i(0);
	long int	l(0);

	l = strtol(_input.c_str(), NULL, 10);
	if (l < INT_MIN)
	{
		std::cerr << "Error: value too small." << std::endl;
		return;
	}
	else if (l > INT_MAX)
	{
		std::cerr << "Error: value too big." << std::endl;
		return;
	}

	i = static_cast<int>(l);

	std::cout << "char: ";
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if(i < 32 || i > 95)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	return;
}

void	Converter::showConvert(float) const{
	double	d(0.0);
	float	f(0.0f);

	if (_input.compare(0, 5, "+inff") == 0)
		d = INFINITY;
	else if (_input.compare(0, 5, "-inff") == 0)
		d = -INFINITY;
	else if (_input.compare(0, 4, "inff") == 0)
		d = INFINITY;
	else if (_input.compare(0, 4, "nanf") == 0)
		d = NAN;
	else
	{
		d = strtod(_input.c_str(), NULL);

		if (d > std::numeric_limits<float>::max())
		{
			std::cerr << "Error: value too big." << std::endl;
			return;
		}
		else if (d < -std::numeric_limits<float>::max())
		{
			std::cerr << "Error: value too small." << std::endl;
			return;
		}
	}

	f = static_cast<float>(d);

	std::cout << "char: ";
	if (static_cast<int>(f) < CHAR_MIN || static_cast<int>(f) > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if(static_cast<int>(f) < 32 || static_cast<int>(f) > 95)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(f) << std::endl;
	std::cout << "int: ";
	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN)
		|| _input.compare(0, 4, "nanf") == 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
	return;
}

void	Converter::showConvert(double) const{
	double	d(0.0);

	if (_input.compare(0, 4, "+inf") == 0)
		d = INFINITY;
	else if (_input.compare(0, 4, "-inf") == 0)
		d = -INFINITY;
	else if (_input.compare(0, 3, "inf") == 0)
		d = INFINITY;
	else if (_input.compare(0, 3, "nan") == 0)
		d = NAN;
	else
	{
		d = strtod(_input.c_str(), NULL);

		if (d == HUGE_VAL)
		{
			std::cerr << "Error: value too big." << std::endl;
			return;
		}
		else if (d == -HUGE_VAL)
		{
			std::cerr << "Error: value too small." << std::endl;
			return;
		}
	}

	std::cout << "char: ";
	if (static_cast<int>(d) < CHAR_MIN || static_cast<int>(d) > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if(static_cast<int>(d) < 32 || static_cast<int>(d) > 95)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(d) << std::endl;
	std::cout << "int: ";
	if (d > static_cast<float>(INT_MAX) || d < static_cast<float>(INT_MIN)
		|| _input.compare(0, 3, "nan") == 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

bool	Converter::_isChar(void) const{
	if (_input.length() > 1)
		return false;
	if (_input[0] < '0' || _input[0] > '9')
		return true;
	return false;
}

bool	Converter::_isInt(void) const{
	if (_input.compare(0, 4, "+inf") == 0)
		return false;
	if (_input.compare(0, 4, "-inf") == 0)
		return false;
	if (_input.compare(0, 3, "inf") == 0)
		return false;
	if (_input.compare(0, 3, "nan") == 0)
		return false;
	if (_input.find('.') == _input.npos)
		return true;
	return false;
}

bool	Converter::_isFloat(void) const{
	if (_input.compare(0, 5, "+inff") == 0)
		return true;
	else if (_input.compare(0, 5, "-inff") == 0)
		return true;
	else if (_input.compare(0, 4, "inff") == 0)
		return true;
	else if (_input.compare(0, 4, "nanf") == 0)
		return true;
	else if (_input.find('f') != _input.npos)
		if (_input.compare(0, 4, "+inf") != 0 && _input.compare(0, 4, "-inf") != 0)
			if (_input.compare(0, 3, "inf") != 0 && _input.compare(0, 3, "nan") != 0)
				return true;
	return false;
}

bool	Converter::_isDouble(void) const{
	if (_input.compare(0, 4, "+inf") == 0)
		return true;
	if (_input.compare(0, 4, "-inf") == 0)
		return true;
	if (_input.compare(0, 3, "inf") == 0)
		return true;
	if (_input.compare(0, 3, "nan") == 0)
		return true;
	if (_input.find('.') != _input.npos)
		return true;
	return false;
}

bool	Converter::_areDigits(void) const{
	if (_input.compare(0, 4, "+inf") == 0)
		return true;
	if (_input.compare(0, 4, "-inf") == 0)
		return true;
	if (_input.compare(0, 3, "inf") == 0)
		return true;
	if (_input.compare(0, 3, "nan") == 0)
		return true;
	for (int i = 0; i < static_cast<int>(_input.length()); i++)
		if (_input[i] >= '0' && _input[i] <= '9')
			return true;
	return false;
}
