/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:05:11 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:01:01 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

#define HUMANB_HPP

#include "Weapon.hpp"
# include <string>

class	HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);
	void	attack(void);
	bool	setWeapon(Weapon& weapon);

private:
	Weapon	*_weapon;
	std::string	_name;
};

#endif
