/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:23:51 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 14:01:32 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & other);

	~ClapTrap(void);
	ClapTrap&	operator=(ClapTrap const & other);
	std::string const &	getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
	bool	setName(std::string const & name);
	bool	setHitPoints(unsigned int amount);
	bool	setEnergyPoints(unsigned int amount);
	bool	setAttackDamage(unsigned int amount);
	bool	is_able_to_interact(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
