/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:30:02 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 20:39:14 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include <string>

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const & other);
	virtual ~WrongCat(void);

	WrongCat& operator=(WrongCat const & other);

	std::string const&	getType(void) const;
	void	makeSound(void) const;
};

#endif
