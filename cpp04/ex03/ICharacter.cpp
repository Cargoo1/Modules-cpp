/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:53:04 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 19:45:28 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"

# include <iostream>

ICharacter::ICharacter(void)
{
	return ;
}

ICharacter::ICharacter(ICharacter const & other)
{
	*this = other;
}

ICharacter::~ICharacter(void)
{
	return ;
}

ICharacter&	ICharacter::operator=(ICharacter const & other)
{
	std::cout << "ICharacter copy operator called\n";
	(void)other;
	return (*this);
}
