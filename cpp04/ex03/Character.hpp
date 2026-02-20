/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:04:57 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 23:29:16 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP

# define CHARACTER_HPP

#include "AMateria.hpp"
#include "Garbage.hpp"
# include "ICharacter.hpp"

class	Character : public ICharacter
{
public:
	Character(void);
	Character(std::string const &name);
	Character(Character const & other);
	~Character(void);

	Character&	operator=(Character const &other);

	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
private:
	std::string	_Name;
	AMateria	*_inventory[INVENTORY_SIZE];
	Garbage		_trashcan;
};

#endif
