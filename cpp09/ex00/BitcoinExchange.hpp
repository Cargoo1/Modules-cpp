/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:28:39 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/01 16:59:49 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Database.hpp"
#include "IDataHandler.hpp"

class	BitcoinExchange : public IDataHandler
{
public:
	BitcoinExchange(Database& database);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange& other);

private:
	virtual	bool	handle_error(const char* msg);
	virtual	bool	check_value(const std::string& value);
	virtual void	handle_data(const std::string& key, const std::string& value);
	Database&		_database;
};
