/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:46:46 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/03 15:02:54 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() : _name("Jhon doe")
{
	std::cout << "Zombie Created" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed" << std::endl;
	return;
}

bool	Zombie::setName(std::string name)
{
	if (name.empty())
		return (false);
	this->_name = name;
	return (true);
}

std::string&	Zombie::getName(void)
{
	return (this->_name);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
