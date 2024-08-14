/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:39:03 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 19:07:26 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon weapon){
	_weapon = weapon;
}

void	HumanB::attack(){
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}