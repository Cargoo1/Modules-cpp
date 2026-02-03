/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:53:27 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/03 16:14:57 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = zombieHorde(1000000000, "lol");
	delete [] heap_zombie;
}
