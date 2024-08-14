/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:58:19 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/14 14:15:04 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	public:
		HumanB() {}
		HumanB(const std::string &name) : _name(name), _weapon(NULL){}
		~HumanB() {}
		void	attack();
		void	setWeapon(Weapon &weapon);
	private:
		std::string _name;
		Weapon *_weapon;
};

#endif