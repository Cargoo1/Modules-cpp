/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:58 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/08 17:53:37 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.hpp"

int	main(void)
{
	int		numbers[9] = {9, 3, 1, 4, 5, 2, 7, 6, 8};
	std::vector<int>	v0(numbers, numbers + 9);
	//merge_sort(v0);
	binary_insertion_sort(v0);
	display_vector(v0);
}
