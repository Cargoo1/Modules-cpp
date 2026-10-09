/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:53:33 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/09 20:40:25 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>

typedef struct pair
{
	int	a;
	int	b;
	pair(int a, int b) : a(a), b(b){};
	bool	operator>(const pair& other) const;
	bool	operator<(const pair& other) const;
}	t_pair;

class	PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& other);
	~PmergeMe(void);

	PmergeMe&	operator=(const PmergeMe& other);

	template<class T> bool		is_greater(T a, T b);
	template<class T> bool		is_smaller(T a, T b);

	std::size_t		getNofComparations(void);

private:
	std::size_t			_number_of_comparations;
	std::vector<int>	_vector;
	std::list<int>		_list;
};

template<class T> bool	PmergeMe::is_greater(T a, T b)
{
	this->_number_of_comparations++;
	return a > b;
}

template<class T> bool	PmergeMe::is_smaller(T a, T b)
{
	this->_number_of_comparations++;
	return a < b;
}
