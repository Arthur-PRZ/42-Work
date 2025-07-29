#include "Point.hpp"

Point::Point() : x(0), y(0)
{
};

Point::Point(const Point& point) : x(point.x), y(point.y) 
{
};

Point::Point(const float& float1, const float& float2) : x(Fixed(float1)), y(Fixed(float2)) 
{
};