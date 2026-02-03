/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChumps.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:52:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/03 15:52:31 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	newZombie;

	newZombie.setName(name);
	newZombie.announce();
	return;
}
