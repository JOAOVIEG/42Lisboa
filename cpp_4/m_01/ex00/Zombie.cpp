/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:26:04 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 13:45:21 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::SetName(void){
	std::cout << "Enter name: " << std::endl;
	std::getline(std::cin, Zombie::_name);
}

void	Zombie::announce(void) {
	std::cout << Zombie::_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
