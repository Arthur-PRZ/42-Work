#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
    std::cout << "=== Test MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements (MutantStack):" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::stack<int> s(mstack);
    std::cout << "Copy to std::stack works, top: " << s.top() << std::endl;

    std::cout << "\n=== Test std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Back: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Elements (std::list):" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}