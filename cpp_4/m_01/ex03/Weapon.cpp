/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:39:11 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/14 13:56:21 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&		Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string weapon_type)
{
	this->type = weapon_type;
}