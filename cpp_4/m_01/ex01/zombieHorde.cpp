/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:44:32 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/23 14:54:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie* ptrToZombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ptrToZombies[i].SetName(name);
		ptrToZombies[i].announce();
	}
	return ptrToZombies;
}
