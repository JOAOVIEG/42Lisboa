/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:10:34 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 14:47:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	public:
		Zombie() {SetName(_name); }
		Zombie(std::string name) : _name(name) { announce(); }
		~Zombie() {std::cout << _name << " destroyed!" << std::endl; }
		void	SetName(std::string name);
		void	announce(void);

	private:
		std::string	_name;
};

Zombie* newZombie( std::string name );
Zombie*	zombieHorde(int N, std::string name);
void	randomChump( std::string name );


#endif