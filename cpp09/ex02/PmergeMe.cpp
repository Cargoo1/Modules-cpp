/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:10:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 22:08:55 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sorts.hpp"
#include <iterator>
#include <vector>
#include <list>

int number_of_comparations = 0;

PmergeMe::PmergeMe(void) : _inserted_elements(0)
{

}

PmergeMe::PmergeMe(const PmergeMe& other) : _inserted_elements(other._inserted_elements)
{
	this->_list = other._list;
	this->_vector = other._vector;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return *this;
	this->~PmergeMe();
	new (this) PmergeMe(other);
	return *this;
}

std::size_t		PmergeMe::get_jacobsthal_number(std::size_t k)
{
	return (std::pow(2, k + 1) + std::pow(-1, k)) / 3;
}

void	PmergeMe::_insert_in_jacobsthal_sequence(std::vector<Group>& v_main, std::vector<Group>& v_pend,
												std::size_t last_b_idx, std::size_t first_b_idx)
{
	std::size_t	pend_idx = 0;
	std::size_t	limit_idx = 0;
	for (std::size_t i = first_b_idx; i >= last_b_idx; --i)
	{
		pend_idx = i - last_b_idx;
		limit_idx = i + this->_inserted_elements;
		if (limit_idx > v_main.size())
			limit_idx = v_main.size();
		std::size_t	temp_idx = binary_search_lower_bound_vector(v_pend[pend_idx], v_main, limit_idx);
		v_main.insert(v_main.begin() + temp_idx, v_pend[pend_idx]);
		v_pend.erase(v_pend.begin() + pend_idx);
		++this->_inserted_elements;
	}
}

void	PmergeMe::merge_insertion_sort(std::vector<Group>& v0)
{
	if (v0.size() <= 1)
		return;
	std::vector<Group>	winners;
	for (std::size_t i = 0; i + 1 < v0.size(); i += 2)
	{
		if (v0[i] > v0[i + 1])
		{
			v0[i].pend.push_back(v0[i + 1]);
			winners.push_back(v0[i]);
		}
		else
		{
			v0[i + 1].pend.push_back(v0[i]);
			winners.push_back(v0[i + 1]);
		}
		++number_of_comparations;
	}
	merge_insertion_sort(winners);
	std::vector<Group>	v_main;
	std::vector<Group>	v_pend;
	for (std::size_t i = 0; i != winners.size(); ++i)
	{
		v_pend.push_back(winners[i].pend.back());
		winners[i].pend.pop_back();
		v_main.push_back(winners[i]);
	}
	std::size_t	max_pend_idx = 0;
	if (v0.size() % 2 == 0)
		max_pend_idx = v0.size() / 2;
	else
	{
		max_pend_idx = (v0.size() / 2) + 1;
		v_pend.push_back(*(v0.end() -  1));
	}
	std::size_t	comparations_budget = 1;
	v_main.insert(v_main.begin(), v_pend[0]);
	v_pend.erase(v_pend.begin());
	++comparations_budget;
	std::size_t	last_b_idx = 1;
	std::size_t	first_b_idx = 1;
	while (v_pend.size() != 0)
	{
		last_b_idx = first_b_idx + 1;
		first_b_idx = get_jacobsthal_number(comparations_budget++);
		if (first_b_idx > max_pend_idx)
			first_b_idx = max_pend_idx;
		this->_insert_in_jacobsthal_sequence(v_main, v_pend, last_b_idx, first_b_idx);
	}
	this->_inserted_elements = 0;
	v0 = v_main;
}

void	PmergeMe::_insert_in_jacobsthal_sequence(std::list<Group>& l_main, std::list<Group>& l_pend,
		std::size_t last_b_idx, std::size_t first_b_idx)
{
	std::size_t	pend_idx = 0;
	std::size_t	limit_idx = 0;
	for (std::size_t i = first_b_idx; i >= last_b_idx; --i)
	{
		pend_idx = i - last_b_idx;
		limit_idx = i + this->_inserted_elements;
		if (limit_idx > l_main.size())
			limit_idx = l_main.size();
		PmergeMe::list_iterator	value_it = l_pend.begin();
		PmergeMe::list_iterator	limit_it = l_main.begin();
		std::advance(value_it, pend_idx);
		std::advance(limit_it, limit_idx);
		PmergeMe::list_iterator temp_it = binary_search_lower_bound_list(*value_it, l_main, limit_it);
		l_main.insert(temp_it, *value_it);
		l_pend.erase(value_it);
		++this->_inserted_elements;
	}
}

void	PmergeMe::merge_insertion_sort(std::list<Group>& list)
{
	if (list.size() <= 1)
		return;
	std::list<Group>	winners;
	for (list_iterator it = list.begin(); calculate_forward_steps(it, list.end(), list.end()) >= 2; std::advance(it, 2))
	{
		list_iterator	current = it;
		list_iterator	next = it;
		std::advance(next, 1);
		if (*current > *next)
		{
			it->pend.push_back(*next);
			winners.push_back(*it);
		}
		else
		{
			next->pend.push_back(*it);
			winners.push_back(*next);
		}
		++number_of_comparations;
	}
	merge_insertion_sort(winners);
	std::list<Group>	l_main;
	std::list<Group>	l_pend;
	for (list_iterator it = winners.begin(); it != winners.end(); ++it)
	{
		l_pend.push_back(it->pend.back());
		it->pend.pop_back();
		l_main.push_back(*it);
	}
	std::size_t	max_pend_idx = 0;
	if (list.size() % 2 == 0)
		max_pend_idx = list.size() / 2;
	else
	{
		max_pend_idx = (list.size() / 2) + 1;
		l_pend.push_back(*(--list.end()));
	}
	std::size_t	comparations_budget = 1;
	l_main.insert(l_main.begin(), *l_pend.begin());
	l_pend.erase(l_pend.begin());
	++comparations_budget;
	std::size_t	last_b_idx = 1;
	std::size_t	first_b_idx = 1;
	while (l_pend.size() != 0)
	{
		last_b_idx = first_b_idx + 1;
		first_b_idx = get_jacobsthal_number(comparations_budget++);
		if (first_b_idx > max_pend_idx)
			first_b_idx = max_pend_idx;
		this->_insert_in_jacobsthal_sequence(l_main, l_pend, last_b_idx, first_b_idx);
	}
	this->_inserted_elements = 0;
	list = l_main;
}
