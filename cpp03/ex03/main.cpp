/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 18:14:07 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
# include "FragTrap.hpp"

int	main(void)
{
	DiamondTrap	test("Cargo");
	test.attack("S");
	test.whoAmi();
}
