/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:03:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/09 23:27:55 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.hpp"

void	display_vector(const std::vector<int>& v)
{
	for (std::size_t i = 0; i != v.size(); ++i)
		std::cout << "v[" << i << "] = " << v[i] << '\n';
}

void	merge(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& v0)
{
	std::size_t	i = 0, j = 0, k = 0;
	while (i != v0.size() && (j != v1.size() || k != v2.size()))
	{
		if (j == v1.size() && k != v2.size())
			v0[i++] = v2[k++];
		else if (k == v2.size() && j != v1.size())
			v0[i++] = v1[j++];
		else if (v1[j] < v2[k])
			v0[i++] = v1[j++];
		else
			v0[i++] = v2[k++];
	}
	
}

void	merge_sort(std::vector<int>& v0)
{
	if (v0.size() <= 1)
		return ;
	std::size_t			n = v0.size();
	std::vector<int>	v1(v0.begin(), v0.begin() + (n / 2));
	std::vector<int>	v2(v0.begin() + n / 2, v0.end());
	merge_sort(v1);
	merge_sort(v2);
	merge(v1, v2, v0);
}
