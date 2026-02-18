/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:03:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 18:12:40 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

# include "ScravTrap.hpp"

class	DiamondTrap : public FragTrap, public ScravTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(std::string const & name);
	DiamondTrap(DiamondTrap const & other);
	~DiamondTrap(void);

	DiamondTrap&	operator=(DiamondTrap const & other);

	void	attack(std::string const & target);
	void	whoAmi(void);
private:
	std::string	_name;
};

#endif
