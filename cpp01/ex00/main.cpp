/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:53:27 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/05 21:46:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = new Zombie;
	heap_zombie->setName("hola");
	heap_zombie->announce();
	delete heap_zombie;
}
