/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/06 17:07:07 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

int	main(void)
{
	ClapTrap	test("test");
	std::cout << test.getHitPoints() << '\n';
	test.attack("aaa");
	test.takeDamage(10000000);
	std::cout << test.getHitPoints() << '\n';
	test.takeDamage(10000000);
	test.setHitPoints(std::numeric_limits<unsigned int>::max() - 100);
	std::cout << test.getHitPoints() << '\n';
	test.beRepaired(200);
	std::cout << test.getHitPoints() << '\n';
}
