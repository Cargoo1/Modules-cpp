/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:30 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/11 22:04:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"
#include <cmath>
#include <cstddef>
#include <ostream>
#include <utility>
#include <vector>

#include <iostream>

extern int	number_of_comparations;


template<class T>
void	merge(std::vector<T>& v1, std::vector<T>& v2, std::vector<T>& v0)
{
	std::size_t	i = 0, j = 0, k = 0;
	while (i != v0.size() && (j != v1.size() || k != v2.size()))
	{
		if (j == v1.size() && k != v2.size())
			v0[i++] = v2[k++];
		else if (k == v2.size() && j != v1.size())
			v0[i++] = v1[j++];
		else
		{
			if (v1[j] < v2[k])
				v0[i++] = v1[j++];
			else
				v0[i++] = v2[k++];
			++number_of_comparations;
		}
	}
	
}

template<class T>
void	merge_sort(std::vector<T>& v0)
{
	if (v0.size() <= 1)
		return ;
	std::size_t			n = v0.size();
	std::vector<T>	v1(v0.begin(), v0.begin() + (n / 2));
	std::vector<T>	v2(v0.begin() + n / 2, v0.end());
	merge_sort(v1);
	merge_sort(v2);
	merge(v1, v2, v0);
}

template<class T>
std::size_t		binary_search_lower_bound(T element, const std::vector<T>& sorted_v, std::size_t limit)
{
	std::size_t	l_idx = 0, r_idx, m_idx;
	if (sorted_v.size() < 1 || limit == 0)
		return 0;
	r_idx = limit;
	l_idx = 0;
	while (l_idx != r_idx)
	{
		m_idx = (r_idx + l_idx) / 2;
		if (element < sorted_v.at(m_idx))
		{
			if (m_idx == l_idx)
				r_idx = l_idx;
			else
				r_idx = m_idx;
		}
		else
			l_idx = m_idx + 1;
		++number_of_comparations;
	}
	return r_idx;
}

template<class T>
void	binary_insertion_sort(std::vector<T>& v0)
{
	if (v0.size() <= 1)
		return;
	std::vector<T>	v0_cpy(v0);
	v0.clear();
	v0.push_back(v0_cpy.front());
	std::size_t	i = 1, temp_idx;
	while (i != v0_cpy.size())
	{
		temp_idx = binary_search_lower_bound(v0_cpy.at(i), v0);
		v0.insert(v0.begin() + temp_idx, v0_cpy.at(i));
		i++;
	}
}
