/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:40:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:21:52 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

# include "HumanA.hpp"

# include "HumanB.hpp"

# include <iostream>

Weapon	test(void)
{
	std::string str = "TESTTT";
	Weapon	lol(str);
	return (lol);
}

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon *club = new Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(*club);
		club->setType("some other type of club");
		jim.attack();
		delete club;
	}
}
