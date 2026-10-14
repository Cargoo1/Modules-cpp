/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:30 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 22:07:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"
#include <cmath>
#include <cstddef>
#include <iterator>
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
std::size_t		binary_search_lower_bound_vector(T element, const std::vector<T>& sorted_v, std::size_t limit)
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

std::size_t	calculate_forward_steps(PmergeMe::list_iterator first, PmergeMe::list_iterator last, PmergeMe::list_iterator end_limit);

int calculate_backwards_steps(PmergeMe::list_iterator first, PmergeMe::list_iterator last, PmergeMe::list_iterator begin_limit);


template<class T>
PmergeMe::list_iterator	binary_search_lower_bound_list(T element, std::list<T>& sorted_list, PmergeMe::list_iterator& limit)
{
	PmergeMe::list_iterator l = sorted_list.begin(), r, m;
	if (sorted_list.size() < 1 || limit == sorted_list.begin())
		return l;
	r = limit;
	while (l != r)
	{
		m = l;
		std::advance(m, calculate_forward_steps(l, r, sorted_list.end()) / 2);
		if (element < *m)
			std::advance(r, calculate_backwards_steps(r, m, sorted_list.begin()));
		else
			std::advance(l, calculate_forward_steps(l, m, sorted_list.end()) + 1);
		++number_of_comparations;
	}
	return r;
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
		temp_idx = binary_search_lower_bound_vector(v0_cpy.at(i), v0);
		v0.insert(v0.begin() + temp_idx, v0_cpy.at(i));
		i++;
	}
}
