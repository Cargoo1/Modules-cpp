/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 16:36:39 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

int	main(void)
{
	FragTrap	frag("cargacho");
	frag.attack("test");
	frag.takeDamage(10);
	frag.highFivesGuys();
	frag.beRepaired(1000);
}
