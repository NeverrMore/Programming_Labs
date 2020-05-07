#pragma once
#include <iterator>
 /*class CPoint{
    double x_;
    double y_;
 public:
    CPoint():x_(0), y_(0){}
    CPoint(int x, int y) : x_(x), y_(y){}
    ~CPoint(){}
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
     bool operator==(CPoint p) const {
         return (x_ == p.getX()) and (y_ == p.getY());
     }
};

class ComparePoints {
public:
    bool operator()(CPoint p) {
        return p == CPoint(0, 0);
    }
};

std::istream& operator >> (std::istream& str, CPoint& p){
    double  x(0), y(0);
    str >> x >> y;
    p = CPoint(x, y);
    return str;
}
*/

//1
template <typename iter, typename object>
bool all_of(iter const begin, iter const end, bool (*func)(object)) {
    for (iter it = begin; it != end; it = std::next(it)) {
        if (!func(*it)) {
            return false;
        }
    }
    return true;
}

//5
template <typename iter, typename object>
bool is_sorted (iter begin, iter end, bool (&func)(object, object)){
    iter previous = begin;
    for (auto it = begin; it != end; it++) {
        if (!func(*previous, *it)) {
            return false;
        }
        previous = it;
    }
    return true;
}

//9
template <typename iter, typename object>
bool is_Palindrome(const iter& begin, const iter& end, bool(&func)(object))
{
    for (iter first = begin, last = std::prev(end); first != last; first = std::next(first), last = std::prev(last)) {
        if (*first != *last) {
            return false;
        }
    }
    return true;
}

