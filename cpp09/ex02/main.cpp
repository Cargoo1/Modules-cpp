/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/12 22:09:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sorts.hpp"
#include <bits/types/struct_timeval.h>
#include <cerrno>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <stdexcept>
#include <vector>
#include <sys/time.h>

std::size_t	calculate_forward_steps(PmergeMe::list_iterator first, PmergeMe::list_iterator last, PmergeMe::list_iterator end_limit)
{
	std::size_t	steps = 0;
	while (first != last && first != end_limit)
	{
		++first;
		++steps;
	}
	return steps;
}

int calculate_backwards_steps(PmergeMe::list_iterator first, PmergeMe::list_iterator last, PmergeMe::list_iterator begin_limit)
{
	int steps = 0;
	while (first != last && first != begin_limit)
	{
		--first;
		--steps;
	}
	return steps;
}

template<class T>
void	display_container(const T& first, const T& last)
{
	for (T it = first; it != last; ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}

long	get_current_time()
{
	struct timeval	current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}	

void	parse_input(std::vector<Group>& vector, std::list<Group>& list, char **argv, std::size_t argc)
{
	std::vector<int>	numbers_seen;
	for (std::size_t i = 1; i < argc; ++i)
	{
		char	*endptr;
		long	n = std::strtol(argv[i], &endptr, 10);
		if (errno == ERANGE || *endptr != '\0' || (n < 0 || n > std::numeric_limits<int>::max()))
			throw std::runtime_error("Error: invalid number");
		for (std::size_t j = 0; j != numbers_seen.size(); ++j)
		{
			if (n == numbers_seen[j])
				throw std::runtime_error("Error: duplicated number");
		}
		numbers_seen.push_back(n);
	}
	for (std::size_t i = 0; i != numbers_seen.size(); ++i)
	{
		Group	temp(numbers_seen[i]);
		vector.push_back(temp);
		list.push_back(temp);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [DIGIT] ...\n";
		return 1;
	}
	std::vector<Group>	vector_0;
	long	start_time;
	long	final_time;
	std::list<Group>	list_0;
	try
	{
		parse_input(vector_0, list_0, argv, argc);
	}catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	std::cout << "Before the sort: \n";
	display_container(vector_0.begin(), vector_0.end());
	std::cout << '\n';
	PmergeMe	pm;
	start_time = get_current_time();
	pm.merge_insertion_sort(vector_0);
	final_time = get_current_time();
	std::cout << "After the sort: \n";
	display_container(vector_0.begin(), vector_0.end());
	std::cout << "Time to process a range of " << vector_0.size() << " elements with std::vector : " << final_time - start_time << '\n';
	std::cout << "Number of comparations = " << number_of_comparations << '\n';
	number_of_comparations = 0;
	start_time = get_current_time();
	pm.merge_insertion_sort(list_0);
	final_time = get_current_time();
	std::cout << "After the sort: \n";
	display_container(list_0.begin(), list_0.end());
	std::cout << "Time to process a range of " << list_0.size() << " elements with std::list : " << final_time - start_time << '\n';
	std::cout << "Number of comparations = " << number_of_comparations << '\n';
}
