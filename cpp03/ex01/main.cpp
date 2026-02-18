/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 16:02:15 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

#include <iostream>

int	main(void)
{
	ScravTrap	scrav("Cargoo");
	scrav.attack("LOL");
	scrav.takeDamage(99);
	std::cout << scrav.getHitPoints() << '\n';
	scrav.beRepaired(1);
	scrav.attack("LOL");
	scrav.takeDamage(1);
	std::cout << scrav.getHitPoints() << '\n';
	scrav.guardGate();
}
