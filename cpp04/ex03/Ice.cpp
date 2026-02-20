/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:44:15 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 21:52:16 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

# include <iostream>

Ice::Ice(void)
{
	this->_type = "ice";
	return ;
}

Ice::Ice(Ice const & other)
{
	*this = other;
	return ;
}

Ice::~Ice(void)
{
	return ;
}

Ice&	Ice::operator=(Ice const & other)
{
	(void)other;
	return (*this);
}

AMateria	*AMateria::clone(void)
{
	AMateria	*newMateria;

	newMateria = new Ice();
	return (newMateria);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() + '\n';
	return ;
}
