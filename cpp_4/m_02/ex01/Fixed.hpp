/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:30:21 by joaocard          #+#    #+#             */
/*   Updated: 2024/09/04 15:32:05 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	private:
		int	integer;
		static const int bits;
		
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float flPtNb);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits( void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif