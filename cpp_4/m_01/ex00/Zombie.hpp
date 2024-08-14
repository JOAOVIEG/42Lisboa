/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:10:34 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 11:52:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	public:
		Zombie() {SetName(); announce(); }
		Zombie(std::string name) : _name(name) { announce(); }
		~Zombie() {std::cout << _name << " destroyed!" << std::endl; }
		void	SetName();
		void	announce(void);

	private:
		std::string	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif