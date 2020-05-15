#include <iostream>
#include <vector>
#include <set>
#include "159_.h"

template<typename T>
bool IsEqual (T x)
{
    return (x > 0 && x < 5);
}

template<typename T>
bool IsSorted (T x, T y)
{
    return (x <= y);
}

int main()
{
    std::cout << "input the size of array: ";
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "input array: ";
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    std::cout << "=======Vector=====" << std::endl;
    std::cout << "All are equal: " << ((all_of(arr.begin(), arr.end(), IsEqual<int>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Sorted: " <<((is_sorted(arr.begin(), arr.end(), IsSorted<int>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Palindrome: " << ((is_palindrome(arr.begin(), arr.end(), IsEqual<int>)) ? "YES" : "NO") << std::endl;

    std::vector<CPoint> Point = {{1, 2}, {3, 4}, {5, 6}};
    std::cout << "=======CPoint=====" << std::endl;
    std::cout << "All of equal: " << ((all_of(Point.begin(), Point.end(), IsEqual<CPoint>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is sorted: " << ((is_sorted(Point.begin(), Point.end(), IsSorted<CPoint>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is palindrome: "<< ((is_palindrome(Point.begin(), Point.end(), IsEqual<CPoint>)) ? "YES" : "NO") << std::endl;

    std::set<double> mySet;
    mySet.insert(2.8);
    mySet.insert(3.7);
    mySet.insert(4.6);
    mySet.insert(5.5);
    mySet.insert(6.4);
    std::cout << "=======Set========" << std::endl;
    std::cout << "All are equal: " << ((all_of(mySet.begin(), mySet.end(), IsEqual<double>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Sorted: " << ((is_sorted(mySet.begin(), mySet.end(), IsSorted<double>)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Palindrome: " << ((is_palindrome(mySet.begin(), mySet.end(), IsEqual<double>)) ? "YES" : "NO") << std::endl;
    return 0;
}
