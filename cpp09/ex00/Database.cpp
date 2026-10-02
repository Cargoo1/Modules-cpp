/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:04:12 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/02 14:16:17 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "DbParser.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

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

void	Database::handle_data(const std::string& key, const std::string& value)
{
	this->_database[key] = std::atof(value.c_str());
}

bool	Database::handle_error(const char* msg)
{
	throw DbParser::ParseError(msg);
}

bool	Database::check_value(const std::string& value)
{
	bool	decimal_point = false;
	for (std::string::const_iterator it = value.begin(); it != value.end(); ++it)
	{
		if (std::isdigit(*it))
			continue;
		else if (*it == '.' && !decimal_point)
		{
			decimal_point = true;
			continue;
		}
		throw DbParser::ParseError("Error: invalid value");
	}
	float	n_value = std::atof(value.c_str());
	if (std::isinf(n_value))
		throw DbParser::ParseError("Error: Value too big");
	int int_value = std::ceil(n_value);
	if (int_value < 0)
		throw DbParser::ParseError("Error: Negative value");
	return true;
}

const std::map<std::string, float>&	Database::getDatabase(void) const
{
	return this->_database;
}
