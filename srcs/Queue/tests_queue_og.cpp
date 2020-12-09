/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_queue_og.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:05 by rofernan          #+#    #+#             */
/*   Updated: 2020/12/09 17:11:21 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

template <class T>
void	print_cap(std::queue<T> que)
{
	std::cout << "que.size(): " << que.size() << std::endl;
	std::cout << "que.empty(): " << que.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(std::queue<T> que)
{
	std::cout << "print content:\n";
	while (!que.empty())
    {
        std::cout << "que.front(): " << que.front() << std::endl;
        que.pop();
    }
	std::cout << std::endl;
}

template <class T>
void	print_access(std::queue<T> que)
{
	std::cout << "que.front(): " << que.front() << std::endl;
	std::cout << "que.back(): " << que.back() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS ORIGINAL QUEUE #################" << std::endl;

	std::queue<int>	que;
	std::queue<int>	que2;

	print_cap(que);

	que.push(2);
	que.push(4);
	que.push(1);
	que.push(10);
	que.push(7);

	std::cout << "********** QUE **********\n";
	print_cap(que);
	print_content(que);
	print_access(que);

	que2 = que;

	std::cout << "********** QUE2 = QUE **********\n";
	print_content(que2);
	print_access(que2);

	std::cout << "********** QUE.POP() **********\n";
	que.pop();
	print_cap(que);
	print_content(que);
	print_access(que);

	std::cout << "********** QUE3(QUE) **********\n";
	std::queue<int>	que3(que);
	print_cap(que3);
	print_content(que3);
	print_access(que3);

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	std::queue<int> foo;
	foo.push(100);
	foo.push(100);
	foo.push(100);
	std::queue<int> bar;
	bar.push(200);
	bar.push(200);

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	std::queue<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
  	std::queue<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
  	std::queue<int> c;
	c.push(30);
	c.push(20);
	c.push(10);
	std::queue<int> d;
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
	std::queue<std::string> str;
	str.push("hello");
	str.push("world");
	print_cap(str);
	print_content(str);
	print_access(str);

	return (0);
}
