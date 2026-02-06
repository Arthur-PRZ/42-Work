#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <vector>
#include <iostream>
#include <limits.h>

class Span
{
    private :

    unsigned int _n;
    std::vector<int> _nbrs;

    public :

    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();

    void addNumber(int nbr);

    int shortestSpan();
    int longestSpan();

    template <typename It>
    void addNbrs(It begin, It end)
    {
        for (It it = begin; it != end; it++)
            addNumber(*it);
    };

    class NotEnoughNbrs : public std::exception
    {
        const char* what() const throw()
        {
            return "Not enough numbers.";
        }
    };

    class SpanFull : public std::exception
    {
        const char* what() const throw()
        {
            return "Span is full.";
        }
    };


};

#endif