#include <iostream>
#include <list>

struct is_near {
  bool operator() (int first, int second)
  { return (abs(first - second) < 5); }
};

bool comp(int first, int second)
{
	return (first > second);
}

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
	lst.splice(lst.end(), lst2, it, it2);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::list<int>::reverse_iterator rit = lst.rbegin();
	std::cout << "rit: " << *rit << std::endl;
	std::cout << std::endl;

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** REMOVE 8s FROM LST **********\n";
	lst.remove(8);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 10s FROM LST **********\n";
	lst.remove(10);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 12s FROM LST **********\n";
	lst.remove(12);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 1s FROM LST **********\n";
	lst.remove(1);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(911);
	lst.push_back(1);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST TEST 2 **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	lst.push_front(11);
	lst.push_front(11);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST TEST 3 **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST PREDICATE **********\n";
	lst.unique(is_near());
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST **********\n";
	lst.sort();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST comp **********\n";
	lst.sort(comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** MERGE LST LST2 **********\n";
	lst.merge(lst2);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST2 ASSIGN(6, 111) **********\n";
	lst2.assign(6, 111);
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** MERGE LST LST2 comp **********\n";
	lst.merge(lst2, comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST **********\n";
	lst.sort();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 ASSIGN(3, 222) **********\n";
	lst2.assign(3, 222);
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** MERGE LST LST2 comp **********\n";
	lst.merge(lst2, comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT EMPTY LST2 **********\n";
	lst2.sort();
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST UNIQUE **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	return (0);
}
