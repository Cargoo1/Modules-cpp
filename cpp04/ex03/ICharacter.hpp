/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:33:18 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 22:51:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

# define INVENTORY_SIZE 4

# include <string>

# include "AMateria.hpp"

class	ICharacter
{
public:
	ICharacter(void);
	ICharacter(ICharacter const & other);
	ICharacter&	operator=(ICharacter const & other);
	virtual	~ICharacter(void);
	virtual std::string const & getName(void) const = 0;
	virtual void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
