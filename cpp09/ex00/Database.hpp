/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:49:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/01 17:19:54 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IDataHandler.hpp"
#include <fstream>
#include <map>
#include <string>
#include "DbParser.hpp"

class	Database : public IDataHandler
{
public:
	Database(void);
	Database(const Database& other);
	~Database(void);

	Database&		operator=(const Database& other);

	void			parse_db_file(const std::string& database_filename, const std::string& sep,
						 const std::string& left_str, const std::string& right_str);
	virtual	void	handle_data(const std::string &key, const std::string &value);
	
	const std::map<std::string, float>&	getDatabase(void) const;
private:
	virtual bool					check_value(const std::string& value);
	virtual	bool					handle_error(const char* msg);
	std::map<std::string, float>	_database;
};
