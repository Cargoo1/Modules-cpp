/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:42:59 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:52:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP

# define CAT_HPP

# include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
public:
	Cat(void);
	Cat(Cat const & other);
	~Cat(void);

	Cat& operator=(Cat const & other);

	std::string const&	getType(void) const;
	void	makeSound(void) const;
	bool	setBrain(std::string const & idea, int idx);
	Brain	*getBrain(void) const;
private:
	Brain	*_myBrain;
};

# endif
