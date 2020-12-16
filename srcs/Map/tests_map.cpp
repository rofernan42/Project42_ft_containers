/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:47:18 by rofernan          #+#    #+#             */
/*   Updated: 2020/12/12 18:47:20 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Map.hpp"

template <class S, class T>
void	print_cap(ft::map<S, T> mp)
{
	std::cout << "mp.size():\t" << mp.size() << std::endl;
	std::cout << "mp.max_size():\t" << mp.max_size() << std::endl;
	std::cout << "mp.empty():\t" << mp.empty() << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_content(ft::map<S, T> mp)
{
	std::cout << "print content with operator[]:\n";
	for (size_t i = 0; i < mp.size(); i++)
		std::cout << "vec[" << i << "]: " << mp[i] << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_content_iterator(ft::map<S, T> mp)
{
	std::cout << "print content with iterarors:\n";
	for (typename ft::map<S, T>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_reverse_iterator(ft::map<S, T> mp)
{
	std::cout << "print content with reverse iterarors:\n";
	for (typename ft::map<S, T>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY MAP #################" << std::endl;

	ft::map<std::string, int> mp;
	ft::map<std::string, int> mp2;
	// ft::map<std::string, int>::iterator it = mp.begin();
	// ft::map<std::string, int>::iterator it2 = mp.begin();

	print_cap(mp);
	// print_content_iterator(mp);

	// mp["aa"] = 4;
	// mp["al"] = 2;
	// mp["ab"] = 8;
	std::cout << "********** MP INSERT **********" << std::endl;
	mp.insert(std::make_pair("l", 10));
	std::cout << mp["l"] << std::endl;
	std::cout << mp["b"] << std::endl;
	mp["a"] = 4;
	mp["q"] = 2;
	mp["i"] = 8;
	mp["p"] = mp["a"];
	mp["o"] = 15;

	mp.print();

	print_cap(mp);
	print_content_iterator(mp);

	// mp.erase("q");
	// mp.erase("b");
	// mp.erase("a");
	// mp.erase("i");
	// std::cout << "erase: " << mp.erase("l") << std::endl;
	// mp.erase(mp.begin());
	// mp.erase(mp.begin(), mp.end());
	// mp.erase("p");
	// mp.erase("a");
	// mp.erase("l");
	// mp.erase("o");
	// mp.clear();
	ft::map<std::string, int>::iterator it = mp.begin();
	it++;
	it++;
	it = mp.end();
	it--;
	mp.erase(it);
	// mp = mp2;
	
	mp.print();

	print_cap(mp);
	print_content_iterator(mp);

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['d']=80;
	mymap['e']=100;
	mymap['g']=100;
	mymap['i']=100;
	mymap['r']=100;
	mymap['u']=100;

	mymap.print();

	itlow=mymap.lower_bound ('b');	// itlow points to b
	itup=mymap.upper_bound ('s');	// itup points to e (not d!)	
	mymap.erase(itlow,itup);		// erases [itlow,itup)

	mymap.print();

	print_cap(mymap);
	print_content_iterator(mymap);

	

	ft::map<char,int> mymap2;

	mymap2['a']=10;
	mymap2['b']=20;
	mymap2['c']=30;
	std::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
	ret = mymap2.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';	
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	mymap.swap(mymap2);

	std::cout << "MYMAP\n";
	print_cap(mymap);
	print_content_iterator(mymap);

	std::cout << "MYMAP2\n";
	print_cap(mymap2);
	print_content_iterator(mymap2);



	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	ft::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";	

    return (0);
}
