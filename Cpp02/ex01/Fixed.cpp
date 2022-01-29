#include "Fixed.hpp"

const int	Fixed::_fBits(8);

Fixed::Fixed(void) : _fpValue(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int integer){
	const int	clr(pow(2, (int)(sizeof(int) * __CHAR_BIT__) - _fBits) - 1);

	std::cout << "Int constructor called" << std::endl;
	_fpValue = (integer & clr) << _fBits;
}

Fixed::Fixed(const float floating){
	int	fracPart(0);
	const float	tte(pow(2, _fBits));
	const int	clr(pow(2, (int)(sizeof(int) * __CHAR_BIT__) - _fBits) - 1);

	std::cout << "Float constructor called" << std::endl;
	_fpValue = ((int)floating & clr) << _fBits;
	fracPart = (int)((floating - (float)((int)floating)) * tte);
	_fpValue = _fpValue | fracPart;
	return;
}

Fixed::Fixed(Fixed const & fixed)
	: _fpValue(fixed.getRawBits()){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &	Fixed::operator=(Fixed const & fixed){
	std::cout << "Assignation operator called" << std::endl;
	_fpValue = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return _fpValue;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	_fpValue = raw;
	return;
}

float	Fixed::toFloat(void) const{
	float		intPart;
	float		fracPart;
	const int	itte(pow(2, _fBits) - 1);
	const float	tte(pow(2, _fBits));

	intPart = (float)(_fpValue >> _fBits);
	fracPart = (float)(_fpValue & itte) / tte;//is this the most accurate mode? sure is more portable
	return intPart + fracPart;
}

int	Fixed::toInt(void) const{
	return roundf(this->toFloat());
}

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed){
	return o << fixed.toFloat();
}