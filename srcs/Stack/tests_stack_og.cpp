/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack_og.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:05 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 16:29:47 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template <class T>
void	print_cap(std::stack<T> stk)
{
	std::cout << "stk.size():\t" << stk.size() << std::endl;
	std::cout << "stk.empty():\t" << stk.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(std::stack<T> stk)
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
void	print_access(std::stack<T> stk)
{
	std::cout << "stk.top():\t" << stk.top() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS ORIGINAL STACK #################" << std::endl;

	std::stack<int>	stk;
	std::stack<int>	stk2;

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
	print_access(stk);

	std::cout << "********** STK.POP() **********\n";
	stk.pop();
	print_cap(stk);
	print_content(stk);
	print_access(stk);

	std::cout << "********** STK3(STK) **********\n";
	std::stack<int>	stk3(stk);
	print_cap(stk3);
	print_content(stk3);
	print_access(stk3);

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	std::stack<int> foo;
	foo.push(100);
	foo.push(100);
	foo.push(100);
	std::stack<int> bar;
	bar.push(200);
	bar.push(200);

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	std::stack<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
  	std::stack<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
  	std::stack<int> c;
	c.push(30);
	c.push(20);
	c.push(10);
	std::stack<int> d;
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

	return (0);
}
