/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:53:27 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/23 18:05:52 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = newZombie("Pablo");
	heap_zombie->announce();
	randomChump("Bob");
	delete heap_zombie;
}
