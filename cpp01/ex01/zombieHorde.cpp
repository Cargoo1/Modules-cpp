/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:02:08 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/03 16:14:07 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

# include <new>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*newHorde;

	newHorde = new(std::nothrow) Zombie[N];
	if (!newHorde)
	{
		std::cout << "New failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		newHorde[i].setName(name);
	return (newHorde);
}
