/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:12:41 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:09:14 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
#include "Weapon.hpp"

# include <iostream>

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void)
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " cant attack without a weapon" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
	return;
}

bool	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return (true);
}
