/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_insertion_sort.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:29:39 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/08 17:52:06 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.hpp"
#include <vector>

std::size_t		binary_search(int n, const std::vector<int>& sorted_v)
{
	std::size_t	l_idx = 0, r_idx, m_idx;
	if (sorted_v.size() <= 1)
		return 0;
	r_idx = sorted_v.size() - 1;
	l_idx = 0;
	while (l_idx != r_idx)
	{
		m_idx = (r_idx + l_idx) / 2;
		if (n < sorted_v.at(m_idx))
		{
			if (m_idx == l_idx)
				r_idx = l_idx;
			else
				r_idx = m_idx - 1;
		}
		else
		{
			if (m_idx + 1 == sorted_v.size())
				l_idx = m_idx;
			else
				l_idx = m_idx + 1;
		}
	}
	return r_idx;
}

void	binary_insertion_sort(std::vector<int>&	v0)
{
	if (v0.size() <= 1)
		return;
	std::vector<int>	v0_cpy(v0);
	v0.clear();
	v0.push_back(v0_cpy.front());
	std::size_t	i = 1, temp_idx;
	while (i != v0_cpy.size())
	{
		temp_idx = binary_search(v0_cpy.at(i), v0);
		if (v0_cpy.at(i) < v0.at(temp_idx))
			v0.insert(v0.begin() + temp_idx, v0_cpy.at(i));
		else
		{
			if (temp_idx + 1 == v0.size())
				v0.push_back(v0_cpy.at(temp_idx));
			else
				v0.insert(v0.begin() + temp_idx + 1, v0_cpy.at(temp_idx));
		}
		i++;
	}
}
