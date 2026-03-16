/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:37:14 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 20:38:40 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <string>

class	WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & other);
	virtual ~WrongAnimal(void);

	WrongAnimal&	operator=(WrongAnimal const & other);

	void	makeSound(void) const;
	std::string const&	getType(void) const;
protected:
	std::string	_type;
};

#endif
