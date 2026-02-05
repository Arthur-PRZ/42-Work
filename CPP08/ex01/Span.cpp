#include "Span.hpp"

Span::Span() : _n(0), _nbrs(0)
{
}

Span::Span(unsigned int n) : _n(n), _nbrs(0)
{
}

Span::Span(const Span &copy) : _n(copy._n), _nbrs(copy._nbrs)
{
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _nbrs = copy._nbrs;
    }
    return *this;

}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
    if (this->_n > _nbrs.size())
        _nbrs.push_back(nbr);
    else
        throw SpanFull();
}

int Span::longestSpan()
{
    if (_n < 2)
        throw NotEnoughNbrs();
    
    std::vector<int>::iterator a = _nbrs.begin();
    std::vector<int>::iterator i = _nbrs.end();
    int longestValue = *a - *i;

    for (; a < _nbrs.end(); a++)
    {
        for(; i < _nbrs.end(); i++)
        {
            if (((a - i) > longestValue) && a > i)
                longestValue = a - i;
        }
    }
    return longestValue;
}

int Span::shortestSpan()
{
    if (_n < 2)
        throw NotEnoughNbrs();
    
    std::vector<int>::iterator a = _nbrs.begin();
    int shortestValue = *a;

    for (; a < _nbrs.end(); a++)
    {
        for(std::vector<int>::iterator i = _nbrs.begin(); i < _nbrs.end(); i++)
        {
            if ((a - i) < shortestValue)
                shortestValue = a - i;
        }
    }
    return shortestValue;
}
