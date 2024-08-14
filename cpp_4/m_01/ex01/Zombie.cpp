/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:26:04 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 14:54:07 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::SetName(std::string name){
		_name = name;
}

void	Zombie::announce(void) {
	std::cout << Zombie::_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
