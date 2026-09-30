/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:04:12 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/30 22:15:59 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>

Database::Database()
{
	return;
}

Database::Database(const Database& other)
{
	this->_database = other._database;
}

Database::~Database(void)
{
	return;
}

Database&	Database::operator=(const Database& other)
{
	if (this == &other)
		return *this;
	new (this) Database(other);
	return *this;
}

Database::DbError::DbError(const char* reason) : _reason(reason)
{
	return;
}

const char*	Database::DbError::what() const throw()
{
	return this->_reason;
}

bool	Database::error_opts(uint8_t opts, const char* str)
{
	if (opts & 0b1)
	{
		std::cout << str;
		return false;
	}
	throw Database::DbError(str);
}

bool	Database::check_date(const std::string& date, uint8_t opts)
{
	int	date_components[3];

	std::size_t	separations[2];
	std::size_t j = 0;
	for	(std::size_t i = 0; i < date.length(); ++i)
	{
		if (date.at(i) == '-'
			&& (i != 0
			&& i != date.length() - 1)
			&& j < 2)
		{
			separations[j++] = i;
			continue;
		}
		else if (std::isdigit(date.at(i)))
			continue;
		return error_opts(opts, "Invalid date\n");
	}
	if (j < 2)
		return error_opts(opts, "invalid date\n");
	date_components[0] = std::atoi(date.substr(0, separations[0]).c_str());
	date_components[1] = std::atoi(date.substr(separations[0] + 1, separations[1] - (separations[0] + 1)).c_str());
	date_components[2] = std::atoi(date.substr(separations[1] + 1, std::string::npos).c_str());
	std::time_t	t = std::time(NULL);
	const std::tm*	Tinfo = std::localtime(&t);
	if ((date_components[0] < 0 || date_components[0] > (1900 + Tinfo->tm_year))
		|| (date_components[1] < 0 || date_components[1] > 12)
		|| (date_components[2] < 0 || date_components[2] > 31))
		return error_opts(opts, "Invalid date\n");
	return true;
}

bool	Database::check_value(const std::string& value, uint8_t opts)
{
	float	n_value = std::strtof(value.c_str(), NULL);
	int int_value = std::ceil(n_value);
	if (int_value < 0 || ((opts >> 1) & 0b1 && int_value > LIMIT))
		return error_opts(opts, "Invalid value\n");
	return true;
}

void	Database::print_btc_value(const std::string& key, const std::string& value)
{
	std::map<std::string, float>::iterator	it = this->_database.lower_bound(key);
	if (it == this->_database.end() || it->first != key)
		--it;
	std::cout << key + " => " + value + " = " << it->second * strtof(value.c_str(), NULL) << '\n';
}

void	Database::parse_db_file(const std::string& database_filename, const std::string& sep,
								const std::string& left_str, const std::string& right_str, uint8_t opts)
{
	std::ifstream ifs(database_filename.c_str(), std::ios_base::in);
	if (!ifs.good())
	{
		std::cout << "Couldnt open database file: " + database_filename;
		throw Database::DbError("");
	}
	std::string	line;
	std::string	date;
	std::string	value;
	while (std::getline(ifs, line))
	{
		if (line.compare(left_str + sep + right_str) == 0)
			continue;
		std::size_t	sep_pos = line.find(sep);
		if ((sep_pos == std::string::npos 
			|| sep_pos == 0
			|| sep_pos == line.length() - 1))
		{
			if (!error_opts(opts, "Bad format\n"))
				continue;
		}
		date = line.substr(0, sep_pos);
		value = line.substr(sep_pos + sep.length(), std::string::npos);
		if (!check_date(date, opts))
			continue;
		if (!check_value(value, opts))
			continue;
		if (opts & 0b1)
		{
			print_btc_value(date, value);
			continue;
		}
		this->_database.insert(std::pair<std::string, float>(date, strtof(value.c_str(), NULL)));
	}
}
