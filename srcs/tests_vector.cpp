/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:05 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/27 17:10:07 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"

int main(void)
{
	ft::vector<int>	vec;
	ft::vector<int>	vec2;

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

	// for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	// vec.assign(2,100);
	// for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	// vec.clear();
	// std::cout << vec[0] << std::endl;
	// std::cout << vec[1] << std::endl;
	// std::cout << vec[2] << std::endl;

	vec2 = vec;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	vec.pop_back();
	vec.push_back(100);
	std::cout << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	std::cout << std::endl;
	std::cout << *vec.erase(vec.begin()+1, vec.begin()+4) << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << std::endl;
	std::cout << "vec.size(): " << vec.size() << std::endl;
	// swap(vec, vec2);
	// vec = vec2;
	vec.swap(vec2);
	std::cout << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	std::cout << std::endl;
	vec2.clear();
	vec2.push_back(455);
	vec2.push_back(234);
	vec2.push_back(1024);
	vec2.push_back(5000);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	std::cout << std::endl;
	vec.swap(vec2);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	std::cout << std::endl;
	vec.pop_back();
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	
	return (0);
}
