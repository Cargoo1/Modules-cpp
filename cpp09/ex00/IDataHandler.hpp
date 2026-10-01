/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDataHandler.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:04:56 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/10/01 17:00:00 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	IDataHandler
{
public:
	virtual ~IDataHandler(void) {};
	virtual void	handle_data(const std::string& key, const std::string& value) = 0;
	virtual	bool	check_value(const std::string& value) = 0;
	virtual	bool	handle_error(const char* msg) = 0;
};
