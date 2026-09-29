/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:09:38 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 19:24:42 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template<class Iterator>void	iterate_container(Iterator begin, Iterator end)
{
	std::cout << "Iterating container:\n";
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

int	main()
{
	{
		std::cout << "MutantStack test:\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top = " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size = " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		iterate_container(it, ite);
		MutantStack<int>::reverse_iterator rev_it = mstack.rbegin();
		MutantStack<int>::reverse_iterator rev_ite = mstack.rend();
		++rev_it;
		--rev_it;
		iterate_container(rev_it, rev_ite);
		std::stack<int> s(mstack);
	}
	{
		std::cout << "std::list test:\n";
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top = " << mstack.front() << std::endl;
		mstack.pop_back();
		std::cout << "size = " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		iterate_container(it, ite);
		std::list<int>::reverse_iterator rev_it = mstack.rbegin();
		std::list<int>::reverse_iterator rev_ite = mstack.rend();
		++rev_it;
		--rev_it;
		iterate_container(rev_it, rev_ite);
		std::list<int> s(mstack);
	}
	{
		std::vector<int> v;
		MutantStack<int, std::vector<int> >	stack;
		stack.push(1);
		MutantStack<int, std::vector<int> > stack2(stack);
		iterate_container(stack2.begin(), stack2.end());
		stack.push(10);
		stack2 = stack;
		iterate_container(stack2.begin(), stack2.end());
		MutantStack<int, std::vector<int> >	stack3;
		iterate_container(stack3.begin(), stack3.end());
		stack3.push(1);
		*stack3.begin() = 20;
		iterate_container(stack3.begin(), stack3.end());
	}
}
