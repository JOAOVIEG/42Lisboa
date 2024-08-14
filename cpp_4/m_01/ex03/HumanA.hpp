/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:10:24 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/14 14:06:41 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) {}
		~HumanA() {}
		
		void	attack();
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif