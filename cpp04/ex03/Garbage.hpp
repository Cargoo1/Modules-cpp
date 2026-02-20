/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Garbage.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:23:08 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 23:43:51 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GARBAGE_HPP

# define GARBAGE_HPP

#include "AMateria.hpp"
#include <cstddef>
class	Garbage
{
public:
	Garbage(void);
	Garbage(size_t size);
	~Garbage(void);
	Garbage(Garbage const & other);

	Garbage&	operator=(Garbage const & other);

	void	add(AMateria *m);
	void	flush(void);
private:
	size_t		_size;
	size_t		_index;
	AMateria	**_trashcan;
};

#endif
