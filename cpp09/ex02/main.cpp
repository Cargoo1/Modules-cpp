/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/10 16:53:17 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sorts.hpp"
#include <utility>
#include <vector>

int	main(void)
{
	int		numbers[11] = {9, 11, 2, 4, 20, 0, 5, 3, 7, 6, 8};
	std::vector<int>	v0(numbers, numbers + 11);
	PmergeMe	pm;
	merge_insertion_sort(v0, pm);
	//binary_insertion_sort(v0, pm);
	display_vector(v0);
	std::cout << pm.getNofComparations();
	merge_sort(v0, pm);
	display_vector(v0);
}
