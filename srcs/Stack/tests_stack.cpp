/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:05 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:42:48 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Stack.hpp"

template <class T>
void	print_cap(ft::stack<T> stk)
{
	std::cout << "stk.size():\t" << stk.size() << std::endl;
	std::cout << "stk.empty():\t" << stk.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(ft::stack<T> stk)
{
	std::cout << "print content (inverted):\n";
	while (!stk.empty())
    {
        std::cout << "stk.top(): " << stk.top() << std::endl;
        stk.pop();
    }
	std::cout <<std::endl;
}

template <class T>
void	print_access(ft::stack<T> stk)
{
	std::cout << "stk.top():\t" << stk.top() << std::endl;
	std::cout <<std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY VECTOR #################" << std::endl;

	ft::stack<int>	stk;
	ft::stack<int>	stk2;

	print_cap(stk);

	stk.push(2);
	stk.push(4);
	stk.push(1);
	stk.push(10);
	stk.push(7);

	print_cap(stk);
	print_content(stk);

	stk2 = stk;

	print_content(stk2);

	stk.pop();
	print_cap(stk);
	print_content(stk);

	return (0);
}
