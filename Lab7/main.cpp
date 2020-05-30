#include "CircularBuffer.h"

int main() {
    CircularBuffer<int> myBuffer(10);
    std::cout << myBuffer << std::endl;
    int command;
    std::cout << "=========Menu=========\n" <<
    "1 add to begin\n" <<
    "2 add to end\n"
    "3 Erase element\n" <<
    "4 insertion\n" <<
    "5 access to first and last elements:\n" <<
    "6 Change buffer capacity\n" <<
    "7 Showing all elements\n" <<
    "8 Standard algorithm\n" <<
    "9 end program" << std::endl;
    std::cout << "please choose command: " << std::endl;

    while (command != 9) {
        std::cin >> command;
        if (command == 1) {
            int el;
            std::cout << "input element: " << std::endl;
            std::cin >> el;
            myBuffer.addFirst(el);
            std::cout << "done.\n";
        }
        else if (command == 2) {
            int el;
            std::cout << "input element: " << std::endl;
            std::cin >> el;
            myBuffer.addLast(el);
            std::cout << "done.\n";
        }
        else if (command == 3) {
            std::cout << "Erase which element?v";
            int num;
            std::cin >> num;
            iterator<int> it = num + myBuffer.begin();
            myBuffer.remove(it);
            std::cout << myBuffer << std::endl << "iterator value after erasing: " << *it;
        }
        else if (command == 4) {
            int el, pos;
            std::cin >> el >> pos;
            myBuffer.add(myBuffer.begin() + pos, el);
            std::cout << "Current data\n" << myBuffer << std::endl;
        }
        else if (command == 5) {
            std::cout << "first: " << myBuffer.GetFirst() << std::endl;
            std::cout << "last: " << myBuffer.GetLast() << std::endl;
        }
        else if (command == 6) {
            std::cout << "Change buffer capacity to: ";
            int num;
            std::cin >> num;
            myBuffer.changeCapacity(num);
            std::cout << myBuffer << std::endl;
        }
        else if (command == 7) {
            std::cout << "Showing all elements: " << std::endl;
            for (int i = 0; i < myBuffer.getSize(); ++i) {
                std::cout << myBuffer[i] << ' ';
            }
        }
        else if (command == 8) {}
        std::cout << "Standard algorithm:\n";
        iterator<int> ans = std::max_element(myBuffer.begin(), myBuffer.end());
        std::cout << myBuffer << std::endl << *ans << std::endl;
    }
    return 0;
}