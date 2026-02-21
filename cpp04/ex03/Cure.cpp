/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:55:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 18:51:29 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include <iostream>
# include "AMateria.hpp"

Cure::Cure(void)
{
	this->_type = "cure";
	return ;
}

Cure::Cure(Cure const & other)
{
	*this = other;
	return ;
}

Cure::~Cure(void)
{
	return ;
}

Cure&	Cure::operator=(Cure const & other)
{
	(void)other;
	return (*this);
}

AMateria	*Cure::clone(void)
{
	AMateria	*newMateria;

	newMateria = new Cure();
	return (newMateria);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds *\n";
	return ;
}
