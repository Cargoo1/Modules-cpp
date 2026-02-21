/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:10:38 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 18:12:12 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	return ;
}

IMateriaSource::IMateriaSource(IMateriaSource const & other)
{
	(void)other;
	return ;
}

IMateriaSource::~IMateriaSource(void)
{
	return ;
}

IMateriaSource&	IMateriaSource::operator=(IMateriaSource const & other)
{
	(void)other;
	return (*this);
}
