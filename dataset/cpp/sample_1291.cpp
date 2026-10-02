#include <iostream>
#include <cstdlib>
#include <ctime>

void main() {
    srand(time(0));
    int supply = 100;
    int demand = rand() % 101 + 50;
    if (supply < demand) {
        std::cout << 'Supply chain disruption detected.' << std::endl;
    } else {
        std::cout << 'Supply chain stable.' << std::endl;
    }
}