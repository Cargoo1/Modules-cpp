/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:49:14 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/23 21:55:03 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

#define ITER_HPP

#include <cstddef>

template <typename T, typename RV> void	iter(T* a, const size_t lenght, RV(*fn)(T& param));

#endif
