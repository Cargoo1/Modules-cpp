/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:33:11 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/05 22:49:27 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

bool	open_file(const char *ifile_name, std::ifstream& ifile_s)
{
	ifile_s.open(ifile_name, std::fstream::in);
	if (!ifile_s.is_open() || !ifile_s.good())
		return (false);
	return (true);
}

bool	create_file(std::string ofile_name, std::ofstream& ofile_s)
{
	ofile_name.append(".replace");
	ofile_s.open(ofile_name.c_str(),
			std::ofstream::out);
	if (!ofile_s.is_open())
		return (false);
	return (true);
}

bool	find_and_replace(std::string& string_to_search,
						std::string& string_to_replace,
						std::string& line)
{
	size_t	found_at;
	size_t	curr_begin;

	found_at = 0;
	curr_begin = 0;
	while (true)
	{
		found_at = line.find(string_to_search, curr_begin);
		if (found_at == std::string::npos)
			break ;
		line.erase(found_at, string_to_search.length());
		line.insert(found_at, string_to_replace);
		curr_begin = found_at + string_to_replace.length();
	}
	return (true);
}

bool	ft_replace(std::string& string_to_search,
					std::string& string_to_replace,
					std::ifstream& ifile_s,
					std::ofstream& ofile_s)
{
	std::string		line;

	while (std::getline(ifile_s, line))
	{
		line.append("\n");
		if (!find_and_replace(string_to_search, string_to_replace, line))
			break ;
		ofile_s << line;
	}
	ifile_s.close();
	ofile_s.close();
	return (true);
}

int	main(int argc, char **argv)
{
	std::string		string_to_search;
	std::string		string_to_replace;
	std::ifstream	ifile_s;
	std::ofstream	ofile_s;

	if (argc != 4)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	string_to_replace = argv[3];
	string_to_search = argv[2];
	if (!open_file(argv[1], ifile_s))
	{
		std::cout << argv[1] << ": error opening the file" << std::endl;
		return (1);
	}
	if (!create_file(argv[1], ofile_s))
	{
		std::cout << "couldnt create a new file" << std::endl;
		return (1);
	}
	if (!ft_replace(string_to_search,
				string_to_replace,
				ifile_s,
				ofile_s))
		return (1);
	return (0);
}
