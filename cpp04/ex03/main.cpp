/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:43:36 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 21:42:03 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
# include "Character.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
#include "MateriaSource.hpp"
#include <ctime>
# include <iostream>

int	main(void)
{
	Character	*pablo = new Character("pablo");
	Character	*bob = new Character("BOBBB");
	IMateriaSource *materias = new MateriaSource();
	AMateria	*tmp;

	materias->learnMateria(new Ice());
	materias->learnMateria(new Cure());
	materias->learnMateria(new Ice());
	materias->learnMateria(new Ice());
	tmp = materias->createMateria("ice");
	bob->equip(tmp);
	tmp = materias->createMateria("Sdasd");
	bob->equip(tmp);
	tmp = materias->createMateria("ice");
	bob->equip(tmp);
	tmp = materias->createMateria("ice");
	bob->equip(tmp);
	tmp = materias->createMateria("ice");
	bob->equip(tmp);
	bob->unequip(2);
	tmp = materias->createMateria("cure");
	bob->equip(tmp);
	std::cout << pablo->getName() + '\n';
	std::cout << bob->getName() + '\n';
	bob->use(2, *pablo);
	pablo->use(-1, *bob);
	delete pablo;
	delete bob;
	delete materias;
	return (0);
}
