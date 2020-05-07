#include <iostream>
#include <vector>
#include <set>
#include "Task159.h"

bool IsEqual (int value){
    return (value > 0 && value < 10);
}
bool isSorted (int x, int y) {
    return x <= y;
}

/*bool IsEqualPoint(CPoint p1, CPoint p2){
    return (p1.getX() < p2.getX() && p1.getY() < p2.getY());
}*/

int main() {
    std::cout << "input the size of array:";
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "input array:";
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    std::cout << "=======Vector=====" << std::endl;
    std::cout << "All are equal: " << ((all_of(arr.begin(), arr.end(), IsEqual)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Sorted: " <<((is_sorted(arr.begin(), arr.end(), isSorted)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Palindrome: " << ((is_Palindrome(arr.begin(), arr.end(), IsEqual)) ? "YES" : "NO") << std::endl;

    /*std::vector<CPoint> P;
    P.push_back(CPoint(0,0));

    std::cout << "=======CPoint=======" << std::endl;
    std::cout << "All are equal: " <<((all_of(P.begin(), P.end(), IsEqualPoint)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Sorted: " <<((is_sorted(P.begin(), P.end(), IsEqualPoint)) ? "YES" : "NO") << std::endl;*/

    std::set<double> Set;
    Set.insert(2.8);
    Set.insert(3.7);
    Set.insert(4.6);
    Set.insert(5.5);
    Set.insert(6.4);
    std::cout << "=======Set========" << std::endl;
    std::cout << "All are equal: " <<((all_of(Set.begin(), Set.end(), IsEqual)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Sorted: " <<((is_sorted(Set.begin(), Set.end(), isSorted)) ? "YES" : "NO") << std::endl;
    std::cout << "Is Palindrome: " << ((is_Palindrome(Set.begin(), Set.end(), IsEqual)) ? "YES" : "NO") << std::endl;
}

