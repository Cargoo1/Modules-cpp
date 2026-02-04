/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:33:42 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 22:04:35 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

# include <string>

class	Weapon
{
public:
	Weapon(std::string str);
	~Weapon(void);
	bool	setType(std::string type);
	const std::string&	getType(void);
private:
	std::string	_type;
};

#endif
