/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:53:27 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/04 17:52:15 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

# include <cstddef>

# define HORDE_SIZE 10

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = zombieHorde(HORDE_SIZE, "lol");
	for (size_t i = 0; i < HORDE_SIZE; i++)
		heap_zombie[i].announce();
	delete [] heap_zombie;
}
