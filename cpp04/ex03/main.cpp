/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:43:36 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/16 13:56:05 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <ctime>
#include <iostream>

#define N 4
int	main(void)
{
	{ // TEST1
		std::cout << "--- TEST1 ---\n";
		Character       *bob = new Character("Bob");
		IMateriaSource  *forge = new MateriaSource();
		AMateria        *tmp;

		forge->learnMateria(new Ice());
		for(int i = 0; i < N; ++i) {
			tmp = forge->createMateria("ice");
			bob->equip(tmp); // passing materia pointer
		}

		for(int i = 0; i < N; i++) {
			bob->unequip(i); // passing materia pointer
		}
		tmp = forge->createMateria("ice");
		bob->equip(tmp);
		bob->unequip(0);
		tmp = forge->createMateria("ice");
		bob->equip(tmp);
		bob->unequip(0);
		std::cout << "--- End of TEST1---\n";
		delete forge;
		delete bob;
	} // DESTRUCTOR CALLED
	{ // TEST2
		std::cout << "--- TEST2 ---\n";
		Character	*bob = new Character("Bob");
		IMateriaSource *forge = new MateriaSource();
		AMateria	*tmp;

		std::cout << bob->getName() + '\n';
		forge->learnMateria(new Ice());
		forge->learnMateria(new Cure());
		forge->learnMateria(new Ice());
		forge->learnMateria(new Ice());
		tmp = forge->createMateria("");
		//NULL pointer
		bob->equip(tmp);
		for(int i = 0; i < N; i++) {
			tmp = forge->createMateria("ice");
			bob->equip(tmp); // passing materia pointer
		}
		bob->unequip(2);
		tmp = forge->createMateria("cure");
		bob->equip(tmp);
		bob->use(2, *bob);
		Character	*bob2 = new Character("Bob2");
		*bob2 = *bob;
		bob2->setName("Bob 2");
		bob2->use(3, *bob2);
		for(int i = 0; i < N; i++) {
			bob2->unequip(i); // unequip materia 
		}
		for(int i = 0; i < N; i++) {
			tmp = forge->createMateria("ice");
			bob2->equip(tmp); // passing materia pointer
		}
		// NO SPACE LEFT
		tmp = forge->createMateria("ice");
		bob2->equip(tmp);
		delete tmp;
		for(int i = 0; i < N; i++) {
			bob2->unequip(i); // unequip materia 
		}
		tmp = forge->createMateria("ice");
		bob2->equip(tmp);
		bob2->unequip(0);
		delete bob;
		tmp = forge->createMateria("ice");
		bob2->equip(tmp);
		tmp = forge->createMateria("ice");
		bob2->equip(tmp);
		tmp = forge->createMateria("cure");
		bob2->equip(tmp);
		tmp = forge->createMateria("ice");
		bob2->equip(tmp);
		ICharacter	*juan = new Character(*bob2);

		std::cout << juan->getName() + '\n';
		juan->setName("Juan");
		juan->use(2, *bob2);
		juan->unequip(0);
		juan->equip(NULL);
		juan->use(000000000, *bob2);
		Ice	*ice_temp = new Ice();
		forge->learnMateria(ice_temp);
		tmp = forge->createMateria("AAAA");
		juan->equip(tmp);
		tmp = forge->createMateria("ice");
		juan->equip(tmp);
		juan->use(0, *juan);
		juan->unequip(0);
		juan->unequip(-1);
		juan->use(0, *juan);
		std::cout << "--- End of TEST2 ---\n";
		delete ice_temp;
		delete forge;
		delete juan;
		delete bob2;
	{

	}

		std::cout << "--- Subject test ---\n";
		IMateriaSource* src = new MateriaSource();
		ICharacter* me = new Character("me");
		AMateria* tmp_2;
		ICharacter* bob_2 = new Character("bob");

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		tmp_2 = src->createMateria("ice");
		me->equip(tmp_2);
		tmp_2 = src->createMateria("cure");
		me->equip(tmp_2);
		me->use(0, *bob_2);
		me->use(1, *bob_2);
		delete bob_2;
		delete me;
		delete src;
	}
	return (0);
}
