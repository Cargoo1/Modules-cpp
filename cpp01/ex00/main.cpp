/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:53:27 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/03 13:00:09 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}


void	randomChump(std::string name)
{
	Zombie	newZombie(name);

	newZombie.announce();
	return;
}

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = newZombie("heap_zombie");
	randomChump("stack_zombie");
	heap_zombie->announce();
	delete heap_zombie;

}
