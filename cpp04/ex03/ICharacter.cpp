/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:53:04 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 22:55:14 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"

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
	(void)other;
	return (*this);
}
