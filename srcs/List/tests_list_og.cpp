#include <iostream>
#include <list>

int main(void)
{
    std::cout << "################# TESTS ORIGINAL LIST #################" << std::endl;

    std::list<int> lst;
    std::list<std::string>lst2;
    lst2.push_back("lala");
    float fl;

    std::cout << fl << std::endl;

    std::cout << lst.size() << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::cout << *it << std::endl;
    std::list<std::string>::iterator it2 = lst2.begin();
    std::cout << "it2: " << *it2 << std::endl;
}