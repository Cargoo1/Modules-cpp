/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DbParser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:30:58 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/10/01 17:14:33 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IDataHandler.hpp"
#include <string>

class	DbParser
{
public:
	class	ParseError : public std::exception
	{
	public:
		ParseError(const char* reason);
		virtual const char*	what() const throw();
	private:
		const char*	_reason;
	};

	static void		parse_db_file(IDataHandler& db_handler, const std::string& database_filename, const std::string& sep,
						 const std::string& left_str, const std::string& right_str);
	static bool		check_date_format(IDataHandler& db_handler, const std::string& date);
private:
	DbParser(void);
	~DbParser(void);
};
