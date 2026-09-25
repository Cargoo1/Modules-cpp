/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:58:53 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/17 21:27:01 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base*	generate(void)
{
	Base*	baseptr = NULL;
	srand(time(NULL));
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			baseptr = new A();
			std::cout << "Choising class A\n";
			break;
		case 1:
			baseptr = new B();
			std::cout << "Choising class B\n";
			break;
		case 2:
			baseptr = new C();
			std::cout << "Choising class C\n";
			break;
		default:
			break;
	}
	return baseptr;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "The derived class is A!\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The derived class is B!\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The derived class is C!\n";
}

void	identify(Base& p)
{
	try
	{
		A& temp = dynamic_cast<A&>(p);
		(void)temp;
		std::cout << "The derived class is A!\n";
		return;
	}
	catch (std::exception& e)
	{}

	try
	{
		B& temp = dynamic_cast<B&>(p);
		(void)temp;
		std::cout << "The derived class is B!\n";
		return;
	}
	catch (std::exception& e)
	{}

	try
	{
		C& temp = dynamic_cast<C&>(p);
		(void)temp;
		std::cout << "The derived class is C!\n";
		return;
	}
	catch (std::exception& e)
	{}
}

int	main()
{
	Base*	baseptr = generate();
	identify(baseptr);
	identify(*baseptr);
}
