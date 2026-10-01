/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:08:53 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/01 17:20:20 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "DbParser.hpp"
#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "Usage: ./btc [DB_FILE]\n";
		return 1;
	}
	Database	db;

	try
	{
		DbParser::parse_db_file(db, "data.csv", ",", "date", "exchange_rate");
	}catch(std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	BitcoinExchange	be(db);
	DbParser::parse_db_file(be, argv[1], " | ", "date", "value");
	return 0;
}
