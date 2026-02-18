/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:43:49 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/18 16:47:49 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP

#define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScravTrap : public ClapTrap
{
public:
	ScravTrap(void);
	ScravTrap(std::string const & name);
	ScravTrap(ScravTrap const & other);
	~ScravTrap(void);

	ScravTrap&	operator=(ScravTrap const & other);
	
	void	guardGate(void);
	void	attack(std::string const & target);

};

#endif
