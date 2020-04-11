#include <iostream>
#include <cmath>
#include <vector>
#include "interface.h"

int main (){
    std::vector <BaseClass*> geoObjects;

    int number;
    std::cout << "Please input the number of figures " << std::endl;
    std::cin >> number;
    if (number > 0){
        std::cout << "Types of objects\n"
                     "1: Circle\n"
                     "2: Equilateral triangle" << std::endl;

        for (int i = 0; i <= number-1; i++) {
            int type;
            do {
                std::cout << "Input type of object: ";
                std::cin >> type;
                std::cout << std::endl;
            }
            while (!(type == 1 || type == 2));

            if (type == 1)
                geoObjects.push_back (new Circle);
            else if (type == 2)
                geoObjects.push_back (new EquilateralTriangle);


            geoObjects.back()->initFromDialog();
        }
    }
    unsigned short command;

    std::cout << "Commands\n"
                 "1. watch all figures\n"
                 "2. overall square\n"
                 "3. overall perimeter\n"
                 "4. Occupied memory\n"
                 "5. The object mass centre\n"
                 "6. Sort by mass\n"
                 "7. finish the program\n" << std::endl;

    std::cout << "Please input command: " << std::endl;

    while (std::cin >> command) {
        if (command == 1) {
            for (auto i : geoObjects) {
                int k = 0;
                std::cout << ++k << ". " << i->classname() << std::endl;
                i->draw();
            }
        }
        else if (command == 2) {
            std::cout << "The sum of squares: ";
            double sumS;
            for (auto i : geoObjects) {
                sumS += i->square();
            }
            std::cout << sumS << std::endl;
        }
        else if (command == 3){
            std::cout << "The sum of perimeter: ";
            double sumP;
            for (auto i : geoObjects) {
                sumP += i->perimeter();
            }
            std::cout << sumP << "\n\n" << std::endl;
        }
        else if (command == 4){
            std::cout << "The occupied memory: ";
            int memory;
            for (auto i : geoObjects) {
                memory += i->size();
            }
            std::cout << memory << "\n\n" << std::endl;
        }
        else if (command == 5){
            std::cout << "The object's mass centres: ";
            CVector2D centre;
            double massSum = 0;
            for (auto i : geoObjects) {
                centre.AB.x += i->position().AB.x * i->mass();
                centre.AB.y += i->position().AB.y * i->mass();
                massSum += i->mass();
            }
            centre.AB.x /= massSum;
            centre.AB.y /= massSum;
            std::cout << "mass center: ";
            centre.PrintVector();
            std::cout << std::endl;
        }
        else if (command == 6){
            sort(geoObjects.begin(), geoObjects.end(), [](BaseClass* x, BaseClass* y){return *x < *y;});
            std::cout << "Sorted." << std::endl;
        }
        else if (command == 7) {
            for (auto &geoObject : geoObjects) {
                delete geoObject;
            }
            return 0;
        }
    }

};