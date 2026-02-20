/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:42:59 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 16:51:59 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const & other);
	~Dog(void);

	Dog& operator=(Dog const & other);

	std::string const&	getType(void) const;
	void	makeSound(void) const;
};

# endif
