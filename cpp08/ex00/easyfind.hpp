/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:15:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 19:00:04 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iterator>
#include <typeinfo>
template<class T>
typename T::iterator	easyfind(T& container, int to_search)
{
	typedef typename T::iterator iter;
	for (iter it = container.begin(); it != container.end(); it++)
	{
		if (*it == to_search)
			return it;
	}
	throw std::exception();
}
