/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:52:32 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 21:54:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP

# define CURE_HPP

# include "AMateria.hpp"

# include "ICharacter.hpp"

class	Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const & other);
	~Cure(void);

	Cure&	operator=(Cure const & other);

	AMateria	*clone(void);
	void		use(ICharacter& target);
};

# endif
