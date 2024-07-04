/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:08:58 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/04 16:27:21 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

std::string		UseMegaphone(std::string str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return str;
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << UseMegaphone(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}
