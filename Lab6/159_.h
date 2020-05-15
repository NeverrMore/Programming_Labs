#pragma once
class CPoint
{
public:
    int x;
    int y;
    
    CPoint(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }

    friend bool operator<(const CPoint &p, int num)
    {
        return (p.x < num && p.y < num);
    }

    friend bool operator>(const CPoint &p, int num)
    {
        return (p.x > num && p.y > num);
    }

    friend bool operator<=(const CPoint &p1, const CPoint &p2)
    {
        return (p1.x <= p2.x && p1.x <= p2.y && p1.y <= p2.x && p1.y <= p2.y);
    }

    friend bool operator==(const CPoint &p, const int num)
    {
        return(p.x == num || p.y == num);
    }

};


template <typename iter, typename Object>
bool all_of(const iter begin, const iter end, bool &func(Object))
{
    for(auto it = begin; it != end; ++it)
    {
        if(!func(*it))
            return false;
    }
    return true;
}

template <typename iter, typename Object>
bool is_sorted(const iter begin, const iter end, bool &func(Object, Object))
{
    for(auto it = begin; it != end; ++it)
    {
        if(!func(*it, *(it + 1)))
            return false;
    }
    return true;
}

template <typename iter, typename object>
bool is_palindrome(const iter& begin, const iter& end, bool(&func)(object))
{
    for(auto itLeft = begin, itRight = std::prev(end); itLeft != end, itRight != begin; itLeft = std::next(itLeft), itRight = std::prev(itRight))
        if (func(*itLeft) ^ func(*itRight))
            return false;
    return true;
}