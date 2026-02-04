/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:32 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/04 21:54:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
# include <string>

# include <iostream>

int	main(void)
{
	std::string	msg = "HI THIS IS BRAIN";
	std::string	*ptr_2_msg = &msg;
	std::string	&ref_2_msg = msg;


	std::cout << "Memory addresses:" << std::endl;
	std::cout << &msg << std::endl;
	std::cout << ptr_2_msg << std::endl;
	std::cout << &ref_2_msg << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << msg << std::endl;
	std::cout << *ptr_2_msg << std::endl;
	std::cout << ref_2_msg << std::endl;
	return (0);
}
