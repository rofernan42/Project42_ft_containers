#include <iostream>
#include "List.hpp"

template <class T>
void	print_cap(ft::list<T> lst)
{
	std::cout << "vec.size():\t" << lst.size() << std::endl;
	std::cout << "vec.max_size():\t" << lst.max_size() << std::endl;
	std::cout << "vec.empty():\t" << lst.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(ft::list<T> lst)
{
	std::cout << "print content with iterarors:\n";
	for (typename ft::list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "*it:\t" << *it << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_access(ft::list<T> lst)
{
	std::cout << "lst.front():\t" << lst.front() << std::endl;
	std::cout << "lst.back():\t" << lst.back() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY LIST #################" << std::endl;

	ft::list<int> lst;
	ft::list<int>::iterator it = lst.begin();
	ft::list<int>::iterator it2 = lst.begin();

	print_cap(lst);
	print_content(lst);
	print_access(lst);

	lst.push_back(3);
	lst.push_back(1234);
	lst.push_back(2);
	lst.push_back(10);
	lst.push_back(45);

	std::cout << "begin: " << *lst.begin() << std::endl;
	std::cout << "end: " << *lst.end() << std::endl;

	print_cap(lst);
	print_content(lst);
	print_access(lst);

	std::cout << "erasing 3rd value...\n";
	it = lst.begin();
	for (int i = 0; i < 3; i++)
		it++;
	
	std::cout << "return value of erase: " << *lst.erase(it) << std::endl;

	print_cap(lst);
	print_content(lst);

	it = lst.end();
	std::cout << "return value of erase end: " << *lst.erase(--it) << std::endl;

	print_cap(lst);
	print_content(lst);

	std::cout << "return value of erase begin: " << *lst.erase(lst.begin()) << std::endl;

	print_cap(lst);
	print_content(lst);

	lst.push_front(42);
	lst.push_front(66);
	lst.push_back(9999);
	lst.push_back(45);
	lst.push_back(333333);

	std::cout << "push front and push back values: " << std::endl;

	print_cap(lst);
	print_content(lst);

	std::cout << "erase begin+2 to begin+5: " << std::endl;
	it = lst.begin();
	for (int i = 0; i < 2; i++)
		it++;
	it2 = lst.begin();
	for (int i = 0; i < 5; i++)
		it2++;
	std::cout << "return value of erase range: " << *lst.erase(it, it2) << std::endl;
	print_cap(lst);
	print_content(lst);

	std::cout << "try erase end(): " << *lst.erase(lst.end()) << std::endl;
	print_cap(lst);
	print_content(lst);

	ft::list<int> lst2(lst);
	std::cout << "print lst2: " << std::endl;
	lst2.push_front(1010101);
	lst2.push_back(949494902);
	print_cap(lst2);
	print_content(lst2);

	ft::list<int> lst3;
	lst3 = lst2;
	std::cout << "print lst3: " << std::endl;
	print_cap(lst3);
	print_content(lst3);

	std::cout << "swap lst lst2: " << std::endl;
	std::cout << "print lst: " << std::endl;
	lst.swap(lst2);
	print_cap(lst);
	print_content(lst);

	std::cout << "print lst2: " << std::endl;
	print_cap(lst2);
	print_content(lst2);

	std::cout << "print lst4(lst.begin(), lst.end()): " << std::endl;
	ft::list<int> lst4(lst.begin(), lst.end());
	print_cap(lst4);
	print_content(lst4);

	std::cout << "lst4.resize(9, 654321): " << std::endl;
	lst4.resize(9, 654321);
	print_cap(lst4);
	print_content(lst4);

	std::cout << "lst4.resize(4): " << std::endl;
	lst4.resize(4);
	print_cap(lst4);
	print_content(lst4);

	lst.clear();
	lst.clear();

	print_content(lst);

	return (0);
}