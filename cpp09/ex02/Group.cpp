/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Group.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:55:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 20:25:32 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Group.hpp"

Group::Group(int winner) : winner(winner)
{

}

Group::Group(const Group& other) : pend(other.pend), winner(other.winner)
{

}

Group::~Group()
{

}

bool	Group::operator<(const Group& other) const
{
	return this->winner < other.winner;
}

bool	Group::operator>(const Group& other) const
{
	return this->winner > other.winner;
}



Group&	Group::operator=(const Group& other)
{
	if (this == &other)
		return *this;
	this->~Group();
	new (this) Group(other);
	return *this;
}

std::ostream&	operator<<(std::ostream& o, const Group& lhs)
{
	o << lhs.winner;
	return o;
}
