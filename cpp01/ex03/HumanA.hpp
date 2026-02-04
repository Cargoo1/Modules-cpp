/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:57:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:10:29 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void	attack(void);
	bool	setWeapon(Weapon& weapon);
private:
	Weapon&		_weapon;
	std::string	_name;
};

#endif
