/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:12:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 21:58:44 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <string>

# include "Brain.hpp"

class	AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const & other);
	virtual ~AAnimal(void);

	AAnimal&	operator=(AAnimal const & other);

	virtual	void	makeSound(void) const=0;
	virtual std::string const&	getType(void) const=0;
	virtual bool	setBrain(std::string const & idea, int idx) = 0;
	virtual Brain*	getBrain(void) const = 0;
protected:
	std::string	_type;
};

# endif
