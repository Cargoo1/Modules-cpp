/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:21:30 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/08 17:50:35 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include <iostream>

void	merge_sort(std::vector<int>& v0);

void	display_vector(const std::vector<int>& v);

void	binary_insertion_sort(std::vector<int>&	v0);
