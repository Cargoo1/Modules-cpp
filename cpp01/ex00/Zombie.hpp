/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:40:08 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/03 12:46:38 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

# include <string>

# include <iostream>

class	Zombie
{
public:

	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);
private:

	std::string	_name;
};

#endif
