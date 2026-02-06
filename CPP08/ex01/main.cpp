#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);


    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Span oneNbr(1);
    oneNbr.addNumber(3);

    try
    {
        oneNbr.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        oneNbr.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Span nbrs(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
        vec.push_back(i);
    nbrs.addNbrs(vec.begin(), vec.end());
    std::cout << nbrs.longestSpan() << std::endl;
    std::cout << nbrs.shortestSpan() << std::endl;
    
}
