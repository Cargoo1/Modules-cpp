/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:54:35 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/10/01 17:02:28 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(Database& db) : _database(db)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
	
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	this->~BitcoinExchange();
	new (this) BitcoinExchange(other);
	return *this;
}

bool	BitcoinExchange::handle_error(const char* msg)
{
	std::cout << msg;
	return false;
}

void	BitcoinExchange::handle_data(const std::string& key, const std::string& value)
{
	std::map<std::string, float>::const_iterator	it = this->_database.getDatabase().lower_bound(key);
	if (it == this->_database.getDatabase().end() || it->first != key)
		--it;
	std::cout << key + " => " + value + " = " << it->second * std::atof(value.c_str()) << '\n';
}

bool	BitcoinExchange::check_value(const std::string& value)
{
	float	n_value = std::strtof(value.c_str(), NULL);
	int int_value = std::ceil(n_value);
	if (int_value < 0 || int_value > 1000)
		return this->handle_error("Error: invalid value\n");
	return true;
}
