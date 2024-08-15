/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:44 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/15 10:11:27 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	typedef	void (Harl::*HarlMbFun)(void);
	struct HarlFunction
	{
		std::string level;
		HarlMbFun	function;
	};
	HarlFunction func[4];
public:
	Harl();
	~Harl();
	
	void	complain(std::string level);
};

bool	check_input(const std::string& input);
#endif