#include <iostream>

void main() {
    int altitude = 30000;
    while (true) {
        if (altitude > 10000) {
            altitude -= 1000;
        }
        std::cout << "Current altitude: " << altitude << " feet" << std::endl;
    }
}