/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:08:53 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/30 22:16:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
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
		db.parse_db_file("data.csv", ",", "date", "exchange_rate", 0);
		db.parse_db_file(argv[1], " | ", "date", "value", USR_MODE | USE_LIMIT);
	}catch(std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
