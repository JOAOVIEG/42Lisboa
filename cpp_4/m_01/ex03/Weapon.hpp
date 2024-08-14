/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:20 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 19:11:12 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	public:
		Weapon(std::string Weapon_type) : type(Weapon_type) {}
		~Weapon() { std::cout << "Weapon destroyed" << std::endl ;}
		
	 	const std::string& 		getType() 	const;
		void					setType(std::string Weapon_type);
	
	private:
		std::string type;
};


#endif