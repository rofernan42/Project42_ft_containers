#include <iostream>
#include <list>

template <class T>
void	print_cap(std::list<T> lst)
{
	std::cout << "vec.size():\t" << lst.size() << std::endl;
	std::cout << "vec.max_size():\t" << lst.max_size() << std::endl;
	std::cout << "vec.empty():\t" << lst.empty() << std::endl;
	std::cout << std::endl;
}

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
	std::cout << "################# TESTS ORIGINAL LIST OPERATIONS #################" << std::endl;

	std::list<int> lst;
	std::list<int> lst2;
	std::list<int>::iterator it;
	std::list<int>::iterator it2;

	for (int i = 0; i < 10; i++)
		lst.push_back(i + 1);
	for (int i = 15; i > 0; i--)
		lst2.push_front(i);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** SPLICE 1 value **********\n";
	it = lst.begin();
	for (int i = 0; i < 4; i++)
		it++;
	std::cout << "it: " << *it << std::endl;
	it2 = lst2.begin();
	for (int i = 0; i < 12; i++)
		it2++;
	std::cout << "it2: " << *it2 << std::endl;
	lst.splice(it, lst2, it2);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);



	std::cout << "********** SPLICE 5 values **********\n";
	it = lst2.begin();
	for (int i = 0; i < 7; i++)
		it++;
	std::cout << "it: " << *it << std::endl;
	it2 = lst2.begin();
	for (int i = 0; i < 12; i++)
		it2++;
	std::cout << "it2: " << *it2 << std::endl;
	lst.splice(lst.begin(), lst2, it, it2);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** REMOVE 8s FROM LST **********\n";
	lst.remove(8);
	print_cap(lst);
	print_content(lst);

	return (0);
}
