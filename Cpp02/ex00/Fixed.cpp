#include "Fixed.hpp"

const int	Fixed::_fBits(8);

Fixed::Fixed(void) : _fpValue(0){
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _fpValue;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	_fpValue = raw;
	return;
}
