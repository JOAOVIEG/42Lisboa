/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:30:11 by joaocard          #+#    #+#             */
/*   Updated: 2024/09/04 15:52:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : integer(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->integer = i << bits;
}

Fixed::Fixed(const float flPtNb) {
	std::cout << "Float constructor called" << std::endl;
	this->integer = static_cast<int>(roundf(flPtNb * (1 << bits)));
}

Fixed::Fixed(const Fixed &other) : integer(other.integer) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &other)
		this->integer = other.integer;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->integer;
}

void Fixed::setRawBits(int const raw) {
	this->integer = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(this->integer) / (1 << bits);
}

int	Fixed::toInt() const {
	return this->integer >> bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}