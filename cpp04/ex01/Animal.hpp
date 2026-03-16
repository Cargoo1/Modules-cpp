/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:12:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 21:06:19 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <string>

class	Animal
{
public:
	Animal(void);
	Animal(Animal const & other);
	virtual ~Animal(void);

	Animal&	operator=(Animal const & other);

	virtual	void	makeSound(void) const;
	virtual std::string const&	getType(void) const;
	virtual	bool setBrain(std::string const &idea, int idx);
protected:
	std::string	_type;
};

# endif
