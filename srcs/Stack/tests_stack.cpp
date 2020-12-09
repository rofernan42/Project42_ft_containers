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
	std::cout << "stk.size(): " << stk.size() << std::endl;
	std::cout << "stk.empty(): " << stk.empty() << std::endl;
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
	std::cout << std::endl;
}

template <class T>
void	print_access(ft::stack<T> stk)
{
	std::cout << "stk.top(): " << stk.top() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY STACK #################" << std::endl;

	ft::stack<int>	stk;
	ft::stack<int>	stk2;

	print_cap(stk);

	stk.push(2);
	stk.push(4);
	stk.push(1);
	stk.push(10);
	stk.push(7);

	std::cout << "********** STK **********\n";
	print_cap(stk);
	print_content(stk);
	print_access(stk);

	stk2 = stk;

	std::cout << "********** STK2 = STK **********\n";
	print_content(stk2);
	print_access(stk2);

	std::cout << "********** STK.POP() **********\n";
	stk.pop();
	print_cap(stk);
	print_content(stk);
	print_access(stk);

	std::cout << "********** STK3(STK) **********\n";
	ft::stack<int>	stk3(stk);
	print_cap(stk3);
	print_content(stk3);
	print_access(stk3);

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	ft::stack<int> foo;
	foo.push(100);
	foo.push(100);
	foo.push(100);
	ft::stack<int> bar;
	bar.push(200);
	bar.push(200);

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	ft::stack<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
  	ft::stack<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
  	ft::stack<int> c;
	c.push(30);
	c.push(20);
	c.push(10);
	ft::stack<int> d;
	d.push(30);
	d.push(20);

  	if (a == b) std::cout << "a and b are equal\n";
  	if (b != c) std::cout << "b and c are not equal\n";
  	if (b < c) std::cout << "b is less than c\n";
  	if (c > b) std::cout << "c is greater than b\n";
  	if (a <= b) std::cout << "a is less than or equal to b\n";
  	if (a >= b) std::cout << "a is greater than or equal to b\n";
	if (c < d) std::cout << "c is less than d\n";
  	if (c > d) std::cout << "c is greater than d\n";

	std::cout << "\n********** TEST STRING STACK **********\n";
	ft::stack<std::string> str;
	str.push("hello");
	str.push("world");
	print_cap(str);
	print_content(str);
	print_access(str);

	return (0);
}
