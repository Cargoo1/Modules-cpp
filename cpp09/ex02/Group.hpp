/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Group.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:54:26 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 20:25:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <vector>

class	Group
{
public:
	Group(int winner);
	Group(const Group& other);
	~Group(void);
	std::vector<Group>	pend;
	int		winner;
	bool	operator<(const Group& other) const;
	bool	operator>(const Group& other) const;
	Group&	operator=(const Group& othe);
};

std::ostream&	operator<<(std::ostream& o, const Group& lhs);
