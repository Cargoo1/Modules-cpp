/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:42:59 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 16:52:11 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const & other);
	virtual ~Cat(void);

	Cat& operator=(Cat const & other);

	std::string const&	getType(void) const;
	void	makeSound(void) const;
};

# endif
