/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:40:08 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/03 16:10:34 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

# include <string>

# include <iostream>

class	Zombie
{
public:

	Zombie(void);
	~Zombie(void);
	void			announce(void);
	Zombie			*newZombie(std::string name);
	void			randomChump(std::string name);
	bool			setName(std::string name);
	std::string&	getName(void);
private:

	std::string	_name;
};

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

Zombie	*zombieHorde(int N, std::string name);
#endif
