/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:37:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:04:29 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string str) : _type(str)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

bool	Weapon::setType(std::string type)
{
	if (type.empty())
		return (false);
	this->_type = type;
	return (true);
}
