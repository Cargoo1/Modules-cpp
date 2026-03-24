/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:17:21 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/23 20:39:53 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

# include <iostream>

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "Function for debug called in main(), level recornized as debug" << std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "Information requested, status OK to have more information try to change this message" << std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "Warning something went wrong..." << std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "FATAL ERROR, kernel no longer working you are on your own now" << std::endl;
	return ;
}

void	Harl::_unknownlevel(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void			(Harl::*functionsMsgs[5])(void) = {&Harl::_debug,
													&Harl::_info,
													&Harl::_warning,
													&Harl::_error,
													&Harl::_unknownlevel};
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t			i;

	i = 0;
	while (i < 4)
	{
		if (!levels[i].compare(level))
		{
			(this->*functionsMsgs[i])();
			return ;
		}
		i++;
	}
	(this->*functionsMsgs[4])();
}
