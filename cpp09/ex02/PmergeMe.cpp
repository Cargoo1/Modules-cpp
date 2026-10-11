/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:10:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/11 22:07:26 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>

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

std::size_t		PmergeMe::get_jacobsthal_number(std::size_t k)
{
	return (std::pow(2, k + 1) + std::pow(-1, k)) / 3;
}

void	PmergeMe::_insert_in_jacobsthal_sequence(std::vector<Group>& v_main, std::vector<Group>& v_pend,
												std::size_t last_jacob, std::size_t current_jacob)
{
	std::size_t	pend_idx = 0;
	std::size_t	limit_idx = 0;
	for (std::size_t i = current_jacob; i > last_jacob; --i)
	{
		pend_idx = i - last_jacob - 1;
		limit_idx = i + this->_inserted_elements;
		if (limit_idx > v_main.size())
			limit_idx = v_main.size();
		std::size_t	temp_idx = binary_search_lower_bound(v_pend[pend_idx], v_main, limit_idx);
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
	std::size_t	last_jacob = 1;
	std::size_t	current_jacob = 1;
	while (v_pend.size() != 0)
	{
		last_jacob = current_jacob;
		current_jacob = get_jacobsthal_number(comparations_budget++);
		if (current_jacob > max_pend_idx)
			current_jacob = max_pend_idx;
		this->_insert_in_jacobsthal_sequence(v_main, v_pend, last_jacob, current_jacob);
	}
	this->_inserted_elements = 0;
	v0 = v_main;
}
