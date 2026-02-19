/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 19:44:21 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	test("Cargo");
	test.attack("enemy");
	test.whoAmi();
	test.guardGate();
	test.highFivesGuys();
}
