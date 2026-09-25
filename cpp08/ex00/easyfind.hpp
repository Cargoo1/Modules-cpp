/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:15:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/25 19:05:58 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iterator>
#include <typeinfo>
template<class T>
typename T::const_iterator	easyfind(T const& first, int second)
{
	typedef typename T::const_iterator iter;
	for (iter it = first.begin(); it != first.end(); it++)
	{
		if (*it == second)
			return it;
	}
	throw std::exception();
}
