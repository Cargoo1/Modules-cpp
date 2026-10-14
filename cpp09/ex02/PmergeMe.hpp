/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:53:33 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 20:18:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <list>
#include <vector>
#include "Group.hpp"
#include <string>

extern int	number_of_comparations;

class	PmergeMe
{
public:
	typedef std::list<Group>::iterator list_iterator;
	PmergeMe(void);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

	PmergeMe&	operator=(const PmergeMe& other);

	void		merge_insertion_sort(std::vector<Group>& vector);
	void		merge_insertion_sort(std::list<Group>& list);
	std::size_t	get_jacobsthal_number(std::size_t k);

private:
	void	_insert_in_jacobsthal_sequence(std::vector<Group>& v_main, std::vector<Group>& v_pend,
										std::size_t last_jacob, std::size_t current_jacob);
	void	_insert_in_jacobsthal_sequence(std::list<Group>& l_main, std::list<Group>& l_pend,
										std::size_t last_jacob, std::size_t current_jacob);

	std::vector<int>	_vector;
	std::size_t			_jacobsthal_sequence[2];
	std::size_t			_inserted_elements;
	std::list<int>		_list;
};
