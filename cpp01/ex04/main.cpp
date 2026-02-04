/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:33:11 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 23:07:04 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(void)
{
	std::fstream file;
	char *str = new char[1000];
	file.open("test.txt", std::fstream::in);
	//file.seekg(file.beg);
	file.read(str, 1000);
	std::cout << str << std::endl;
}
