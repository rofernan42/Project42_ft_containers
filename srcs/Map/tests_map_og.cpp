/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_og.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:47:25 by rofernan          #+#    #+#             */
/*   Updated: 2020/12/12 18:47:27 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

template <class S, class T>
void	print_cap(std::map<S, T> mp)
{
	std::cout << "mp.size():\t" << mp.size() << std::endl;
	std::cout << "mp.max_size():\t" << mp.max_size() << std::endl;
	std::cout << "mp.empty():\t" << mp.empty() << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_content(std::map<S, T> mp)
{
	std::cout << "print content with operator[]:\n";
	for (S i = 0; i < mp.size(); i++)
		std::cout << "vec[" << i << "]: " << mp[i] << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_content_iterator(std::map<S, T> mp)
{
	std::cout << "print content with iterarors:\n";
	for (typename std::map<S, T>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_reverse_iterator(std::map<S, T> mp)
{
	std::cout << "print content with reverse iterarors:\n";
	for (typename std::map<S, T>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
		std::cout << "*it:\t" << *it << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY MAP #################" << std::endl;

	std::map<std::string, int> mp;
	std::map<std::string, int>::iterator it = mp.begin();
	std::map<std::string, int>::iterator it2 = mp.begin();

	print_cap(mp);
	print_content_iterator(mp);

	mp["bb"] = 10;
	mp["aa"] = 4;
	mp["al"] = 2;
	mp["ab"] = 8;

	std::cout << mp["ac"] << std::endl;

	print_cap(mp);
	print_content_iterator(mp);
	
    return (0);
}
