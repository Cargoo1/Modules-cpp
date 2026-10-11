/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/11 22:05:01 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sorts.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>

void	display_vector(std::vector<Group>& v)
{
	for (std::size_t i = 0; i != v.size(); ++i)
		std::cout << "v[" << i << "] = " << v[i].winner << '\n';
}

int	main(void)
{
	//int		numbers[21] = {9, 11, 2, 4, 20, 0, 5, 3, 7, 6, 8};
	std::vector<Group>	v0;
	std::srand(std::time(NULL));
	for (std::size_t i = 0; i < 21; i++)
		v0.push_back(Group(i));
	std::random_shuffle(v0.begin(), v0.end());
	display_vector(v0);
	PmergeMe	pm;
	pm.merge_insertion_sort(v0);
	//binary_insertion_sort(v0, pm);
	display_vector(v0);
	std::cout << number_of_comparations << '\n';
	//merge_sort(v0);
	//display_vector(v0);
}
