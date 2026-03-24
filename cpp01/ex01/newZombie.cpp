/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:51:06 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 17:43:34 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
#include <new>

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new(std::nothrow) Zombie;
	newZombie->setName(name);
	return (newZombie);
}

