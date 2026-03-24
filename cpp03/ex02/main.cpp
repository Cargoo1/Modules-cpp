/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/06 17:20:22 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
#include "ScravTrap.hpp"

int	main(void)
{
	FragTrap	frag("cargacho");
	frag.attack("test");
	frag.takeDamage(10);
	frag.highFivesGuys();
	frag.beRepaired(1000);
	ScravTrap	scra("cargacho");
	scra.attack("test");
	scra.takeDamage(10);
	scra.beRepaired(1000);
	scra.guardGate();
}
