#include <iostream>
#include"STack.h"

//А
template <class Type>
Type findMax(Type *array, size_t n, Type max){
    for (int i = 1; i < n; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

void printError(StackException &e){
    std::cout << "error: " << e.what();
}

int main() {
    int command;
    std::cout << "MENU\n" <<
              "1. Task A\n" <<
              "2. Task E\n" << std::endl;

    std::cout << "please input number of command: ";
    std::cin >> command;

    if (command < 1 || command > 3){
        std::cout << "wrong command" << std::endl;
    }
    //A
    else if (command == 1){
        size_t n;
        std::cout << "input the size of array:" << std::endl;
        std::cin >> n;
        double array[n];

        std::cout << "input array:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        std::cout << "max is " << findMax(array, n, array[0]) << std::endl;
    }
    //E
    else if (command == 2){
        Stack<int, 1> s;
        std::cout << "MENU\n" <<
                  "1. push\n" <<
                  "2. pop\n" << std::endl;

        std::cout << "please input number of command: ";
        int command;
        std::cin >> command;

        if (command < 1 || command > 2) {
            std::cout << "wrong command" << std::endl;
        }

        if (command == 1) {
            s.Push(6);
            try
            {
                s.Push(8);
            }
            catch (StackOverflow& e){
                printError(e);
            }

        } else if (command == 2) {
            try
            {
                s.Pop();
            }
            catch (EmptyStack& e){
                printError(e);
            }
        }
    }
}
