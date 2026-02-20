/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:40:44 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 21:51:18 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICE_HPP

# define ICE_HPP

#include "AMateria.hpp"

# include "ICharacter.hpp"

class	Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const & other);
	~Ice(void);

	Ice&	operator=(Ice const & other);

	AMateria	*clone(void);
	void		use(ICharacter& target);
};

#endif
