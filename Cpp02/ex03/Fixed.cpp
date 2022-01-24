#include "Fixed.hpp"

const int	Fixed::_fBits(8);

Fixed::Fixed(void) : _fpValue(0){
	return;
}

Fixed::Fixed(const int integer){
	const int	clr(pow(2, (int)(sizeof(int) * __CHAR_BIT__) - _fBits) - 1);

	_fpValue = (integer & clr) << _fBits;
}

Fixed::Fixed(const float floating){
	int	fracPart(0);
	const float	tte(pow(2, _fBits));
	const int	clr(pow(2, (int)(sizeof(int) * __CHAR_BIT__) - _fBits) - 1);

	_fpValue = ((int)floating & clr) << _fBits;
	fracPart = (int)((floating - (float)((int)floating)) * tte);
	_fpValue = _fpValue | fracPart;
	return;
}

Fixed::Fixed(Fixed const & fixed)
	: _fpValue(fixed.getRawBits()){
	return;
}

Fixed::~Fixed(void){
	return;
}

Fixed &	Fixed::operator=(Fixed const & fixed){
	_fpValue = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & fixed){
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(Fixed const & fixed){
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(Fixed const & fixed){
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(Fixed const & fixed){
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(Fixed const & fixed){
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(Fixed const & fixed){
	return this->getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & fixed){
	Fixed	res;

	res.setRawBits(this->getRawBits() + fixed.getRawBits());
	return res;
}

Fixed	Fixed::operator-(Fixed const & fixed){
	Fixed	res;

	res.setRawBits(this->getRawBits() - fixed.getRawBits());
	return res;
}

Fixed	Fixed::operator*(Fixed const & fixed){
	Fixed	res;

	res.setRawBits((this->getRawBits() * fixed.getRawBits()) >> _fBits);
	return res;
}

Fixed	Fixed::operator/(Fixed const & fixed){
	Fixed	res;

	res.setRawBits((this->getRawBits() / fixed.getRawBits()) << _fBits);
	return res;
}

Fixed &	Fixed::operator++(void){
	this->setRawBits(this->getRawBits() + 1);

	return *this;
}

Fixed 	Fixed::operator++(int){
	Fixed	res(*this);

	this->setRawBits(this->getRawBits() + 1);
	return res;
}

Fixed &	Fixed::operator--(void){
	this->setRawBits(this->getRawBits() - 1);

	return *this;
}

Fixed 	Fixed::operator--(int){
	Fixed	res(*this);

	this->setRawBits(this->getRawBits() - 1);
	return res;
}

int	Fixed::getRawBits(void) const{
	return _fpValue;
}

void	Fixed::setRawBits(int const raw){
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
	return _fpValue >> _fBits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed){
	return o << fixed.toFloat();
}

Fixed &	Fixed::min(Fixed & a, Fixed & b){
	if (a <= b)
		return a;
	else if (b < a)
		return b;
	return a;
}

const Fixed &	Fixed::min(const Fixed & a, const Fixed & b){
	if (a.getRawBits() <= b.getRawBits())
		return a;
	else if (b.getRawBits() < a.getRawBits())
		return b;
	return a;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b){
	if (a >= b)
		return a;
	else if (b < a)
		return b;
	return a;
}

const Fixed &	Fixed::max(const Fixed & a, const Fixed & b){
	if (a.getRawBits() >= b.getRawBits())
		return a;
	else if (b.getRawBits() > a.getRawBits())
		return b;
	return a;
}