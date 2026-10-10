/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:30 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/10 17:07:45 by alejandrocama    ###   ########.fr       */
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

template<class T>
void	display_vector(std::vector<T>& v)
{
	for (std::size_t i = 0; i != v.size(); ++i)
		std::cout << "v[" << i << "] = " << v.at(i) << '\n';
}

template<class T>
void	merge(std::vector<T>& v1, std::vector<T>& v2, std::vector<T>& v0, PmergeMe& pm)
{
	std::size_t	i = 0, j = 0, k = 0;
	while (i != v0.size() && (j != v1.size() || k != v2.size()))
	{
		if (j == v1.size() && k != v2.size())
			v0[i++] = v2[k++];
		else if (k == v2.size() && j != v1.size())
			v0[i++] = v1[j++];
		else if (pm.is_smaller(v1[j], v2[k]))
			v0[i++] = v1[j++];
		else
			v0[i++] = v2[k++];
	}
	
}

template<class T>
void	merge_sort(std::vector<T>& v0, PmergeMe& pm)
{
	if (v0.size() <= 1)
		return ;
	std::size_t			n = v0.size();
	std::vector<T>	v1(v0.begin(), v0.begin() + (n / 2));
	std::vector<T>	v2(v0.begin() + n / 2, v0.end());
	merge_sort(v1, pm);
	merge_sort(v2, pm);
	merge(v1, v2, v0, pm);
}

template<class T>
std::size_t		binary_search_lower_bound(T element, const std::vector<T>& sorted_v, PmergeMe& pm, std::size_t limit)
{
	std::size_t	l_idx = 0, r_idx, m_idx;
	if (sorted_v.size() < 1 || limit == 0)
		return 0;
	r_idx = limit;
	l_idx = 0;
	while (l_idx != r_idx)
	{
		m_idx = (r_idx + l_idx) / 2;
		if (pm.is_smaller(element, sorted_v.at(m_idx)))
		{
			if (m_idx == l_idx)
				r_idx = l_idx;
			else
				r_idx = m_idx;
		}
		else
			l_idx = m_idx + 1;
	}
	return r_idx;
}

template<class T>
void	binary_insertion_sort(std::vector<T>& v0, PmergeMe& pm)
{
	if (v0.size() <= 1)
		return;
	std::vector<T>	v0_cpy(v0);
	v0.clear();
	v0.push_back(v0_cpy.front());
	std::size_t	i = 1, temp_idx;
	while (i != v0_cpy.size())
	{
		temp_idx = binary_search_lower_bound(v0_cpy.at(i), v0, pm);
		v0.insert(v0.begin() + temp_idx, v0_cpy.at(i));
		i++;
	}
}

std::size_t	get_jacobsthal_number(std::size_t k)
{
	return (std::pow(2, k + 1) + std::pow(-1, k)) / 3;
}

template<class T>
void	merge_insertion_sort(std::vector<T> v0, PmergeMe& pm)
{
	if (v0.size() <= 1)
		return;
	std::vector<t_pair>	v_pairs;
	for (std::size_t i = 0; i + 1 != v0.size(); i += 2)
	{
		if (pm.is_greater(v0[i], v0[i + 1]))
			v_pairs.push_back(t_pair(v0[i], v0[i + 1]));
		else
			v_pairs.push_back(t_pair(v0[i + 1], v0[i]));
	}
	merge_sort(v_pairs, pm);
	std::size_t	comparations_budget = 1;
	std::size_t	inserted_elements = 0;
	std::size_t	erased_elements = 0;
	std::vector<T>	v_main;
	std::size_t	max_j;
	if (v0.size() % 2 == 0)
		max_j = v0.size() / 2;
	else
		max_j = (v0.size() / 2) + 1;
	std::vector<T>	v_pend;
	for (std::size_t i = 0; i != v_pairs.size(); ++i)
		v_pend.push_back(v_pairs[i].b);
	if (v0.size() % 2 != 0)
		v_pend.push_back(*(v0.end() -  1));
	v_main.push_back(v_pend[0]);
	v_pend.erase(v_pend.begin());
	++comparations_budget;
	for (std::size_t i = 0; i != v_pairs.size(); ++i)
		v_main.push_back(v_pairs[i].a);
	bool		is_max_j_reached = false;
	std::size_t	jacobstshal_sequence[2];
	while (v_pend.size() != 0)
	{
		if (!is_max_j_reached)
		{
			jacobstshal_sequence[0] = get_jacobsthal_number(comparations_budget++);
			if (jacobstshal_sequence[0] > max_j)
			{
				is_max_j_reached = true;
				continue;
			}
		}
		else
		{
			jacobstshal_sequence[0] = v_pend.size() - 1;
			if (v_pend.size() == 1)
				jacobstshal_sequence[1] = jacobstshal_sequence[0];
		}
		jacobstshal_sequence[1] = jacobstshal_sequence[0] - 1;
		std::size_t	limit_idx = 0;
		std::size_t	pend_idx = 0;
		for (std::size_t i = 0; i != 2; ++i)
		{
			if (i == 1)
				pend_idx = pend_idx - 1;
			else
				pend_idx = jacobstshal_sequence[i] - 2 - erased_elements;
			if (pend_idx == pend_idx + 2 + erased_elements)
				limit_idx = v_main.size() + 1;
			else
				limit_idx = jacobstshal_sequence[i] + inserted_elements;
			std::size_t	temp_idx = binary_search_lower_bound(v_pend[pend_idx], v_main, pm, limit_idx);
			v_main.insert(v_main.begin() + temp_idx, v_pend[pend_idx]);
			v_pend.erase(v_pend.begin() + pend_idx);
			++inserted_elements, ++erased_elements;
		}
	}
}
