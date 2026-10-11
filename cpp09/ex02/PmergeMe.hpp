/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:53:33 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/11 21:59:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <list>
#include <utility>
#include <vector>
#include "sorts.hpp"
#include <string>

extern int	number_of_comparations;

struct	Group
{
	int		winner;
	Group(int winner) : winner(winner){};
	~Group(void){};
	std::vector<Group>	pend;
	bool	operator<(const Group& other) const;
	bool	operator>(const Group& other) const;
	Group&	operator=(const Group& othe);
};

class	PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

	PmergeMe&	operator=(const PmergeMe& other);

	void		merge_insertion_sort(std::vector<Group>& vector);
	std::size_t	get_jacobsthal_number(std::size_t k);
	void		setVector(const std::vector<std::string>& str);

private:
	void	_insert_in_jacobsthal_sequence(std::vector<Group>& v_main, std::vector<Group>& v_pend,
										std::size_t last_jacob, std::size_t current_jacob);

	std::vector<int>	_vector;
	std::size_t			_jacobsthal_sequence[2];
	std::size_t			_inserted_elements;
	std::list<int>		_list;
};
