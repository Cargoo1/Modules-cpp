/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:50:06 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/09 13:01:20 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	karen;

	if (argc > 2 || argc < 2)
		return (1);
	karen.complain(argv[1]);
	return (0);
}
