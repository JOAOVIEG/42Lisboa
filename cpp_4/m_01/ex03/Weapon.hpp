/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:20 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/14 13:56:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	public:
		Weapon() {}
		Weapon(const std::string& weapon_type) : type(weapon_type) {}
		~Weapon() {std::cout << "Weapon destroyed" << std::endl;};
		
	 	const std::string&		getType();
		void					setType(std::string weapon_type);
	
	private:
		std::string type;
};


#endif