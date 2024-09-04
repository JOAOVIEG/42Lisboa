/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:14:50 by joaocard          #+#    #+#             */
/*   Updated: 2024/09/04 13:38:44 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
	private:
		int	integer;
		static const int bits;
		
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits( void) const;
		void	setRawBits(int const raw);
};


#endif