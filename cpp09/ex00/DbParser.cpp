/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DbParser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:17:37 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/10/01 17:14:50 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DbParser.hpp"
#include "Database.hpp"
#include "IDataHandler.hpp"
#include <fstream>
#include <iostream>

DbParser::DbParser(void)
{

}

DbParser::~DbParser(void)
{

}

DbParser::ParseError::ParseError(const char* reason) : _reason(reason)
{
	return;
}

const char*	DbParser::ParseError::what() const throw()
{
	return this->_reason;
}

bool	DbParser::check_date_format(IDataHandler& db_handler, const std::string& date)
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
		return db_handler.handle_error("Error: Invalid date\n");
	}
	if (j < 2)
		return db_handler.handle_error("Error: Invalid date\n");
	date_components[0] = std::atoi(date.substr(0, separations[0]).c_str());
	date_components[1] = std::atoi(date.substr(separations[0] + 1, separations[1] - (separations[0] + 1)).c_str());
	date_components[2] = std::atoi(date.substr(separations[1] + 1, std::string::npos).c_str());
	std::time_t	t = std::time(NULL);
	const std::tm*	Tinfo = std::localtime(&t);
	if ((date_components[0] < 0 || date_components[0] > (1900 + Tinfo->tm_year))
		|| (date_components[1] < 0 || date_components[1] > 12)
		|| (date_components[2] < 0 || date_components[2] > 31))
		return db_handler.handle_error("Error: Invalid date\n");
	return true;
}

void	DbParser::parse_db_file(IDataHandler& db_handler,
					const std::string& database_filename, const std::string& sep,
					const std::string& left_str, const std::string& right_str)
{
	std::ifstream ifs(database_filename.c_str(), std::ios_base::in);
	if (!ifs.good())
	{
		std::cout << "Couldnt open database file: " + database_filename;
		throw DbParser::ParseError("");
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
			if (!db_handler.handle_error("Error: Bad format\n"))
				continue;
		}
		date = line.substr(0, sep_pos);
		value = line.substr(sep_pos + sep.length(), std::string::npos);
		if (!DbParser::check_date_format(db_handler, date) || !db_handler.check_value(value))
			continue;
		db_handler.handle_data(date, value);
	}

}
