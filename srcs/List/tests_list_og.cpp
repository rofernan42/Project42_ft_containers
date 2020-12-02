#include <iostream>
#include <list>

template <class T>
void	print_content(std::list<T> lst)
{
	std::cout << "print content with iterarors:\n";
	for (typename std::list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "*it:\t" << *it << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_access(std::list<T> lst)
{
	std::cout << "lst.front():\t" << lst.front() << std::endl;
	std::cout << "lst.back():\t" << lst.back() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS ORIGINAL LIST #################" << std::endl;

	std::list<int> lst;
	std::list<std::string> lst2(5, "lala");

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(2);

	std::cout << *lst.begin() << std::endl;

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "*it:\t" << *it << std::endl;

	for (std::list<std::string>::iterator it2 = lst2.begin(); it2 != lst2.end(); it2++)
		std::cout << "*it2:\t" << *it2 << std::endl;
	print_content(lst);
	print_access(lst);
}