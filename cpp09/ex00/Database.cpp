/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:04:12 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/01 17:19:45 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
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
	float	n_value = std::strtof(value.c_str(), NULL);
	int int_value = std::ceil(n_value);
	if (int_value < 0)
		throw DbParser::ParseError("Error: Negative value\n");
	return true;
}

const std::map<std::string, float>&	Database::getDatabase(void) const
{
	return this->_database;
}
