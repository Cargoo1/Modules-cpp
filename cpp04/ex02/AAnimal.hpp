/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:12:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:52:02 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <string>

class	AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const & other);
	virtual ~AAnimal(void);

	AAnimal&	operator=(AAnimal const & other);

	virtual	void	makeSound(void) const=0;
	virtual std::string const&	getType(void) const=0;
protected:
	std::string	_type;
};

# endif
