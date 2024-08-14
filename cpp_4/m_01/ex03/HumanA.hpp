/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:10:24 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 18:39:10 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA() {}
		HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {}
		
		void	attack();
	private:
		std::string _name;
		Weapon _weapon;
};

#endif