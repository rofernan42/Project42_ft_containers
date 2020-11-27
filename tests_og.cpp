/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:02:24 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/13 12:02:39 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int>	vec;
	std::vector<int>	vec2;

	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout <<std::endl;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(10);
	vec.push_back(15);
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << std::endl;
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	std::cout << vec[50] << std::endl;
	try {
		std::cout << vec.at(1) << std::endl;
		std::cout << vec.at(10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	// vec.assign(2,100);
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	// vec.clear();
	// std::cout << vec[0] << std::endl;
	// std::cout << vec[1] << std::endl;
	// std::cout << vec[2] << std::endl;

	vec2 = vec;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << "   " << vec2[i] << std::endl;
	vec.pop_back();
	vec.push_back(100);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << "   " << vec2[i] << std::endl;
	std::cout << std::endl;
	std::cout << *vec.erase(vec.begin()+1, vec.begin()+4) << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	return (0);
}
