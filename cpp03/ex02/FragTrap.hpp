/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:12:50 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 16:34:26 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & other);
	~FragTrap(void);

	FragTrap&	operator=(FragTrap const & other);

	void	attack(std::string const & target);
	void	highFivesGuys(void);
};

#endif
