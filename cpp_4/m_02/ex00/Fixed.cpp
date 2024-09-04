/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:32:28 by joaocard          #+#    #+#             */
/*   Updated: 2024/09/04 14:06:00 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : integer(0) { 
	std::cout << "Default constructor called" << std::endl;
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