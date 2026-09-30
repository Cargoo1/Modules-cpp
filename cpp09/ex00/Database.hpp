/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:49:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/30 22:05:44 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "stdint.h"
#include <exception>
#include <fstream>
#include <map>
#include <string>
#include <sys/types.h>

#define LIMIT 1000
#define USR_MODE 0b1
#define USE_LIMIT 0b10

class	Database
{
public:
	class	DbError : public std::exception
	{
	public:
		DbError(const char* reason);
		virtual const char*	what() const throw();
	private:
		const char*	_reason;
	};
	Database(void);
	Database(const Database& other);
	~Database(void);

	Database&	operator=(const Database& other);

	void	parse_db_file(const std::string& database_filename, const std::string& sep,
						 const std::string& left_str, const std::string& right_str, uint8_t opts);
	
	const std::map<std::string, float>&	getDatabase(void);
private:
	bool							check_date(const std::string& date, uint8_t opts);
	bool							check_value(const std::string& value, uint8_t opts);
	bool							error_opts(uint8_t opts, const char* str);
	void							print_btc_value(const std::string& key, const std::string& value);

	std::map<std::string, float>	_database;
};
