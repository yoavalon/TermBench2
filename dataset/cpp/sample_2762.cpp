#include <iostream>

void flight_planner() {
    int a = 10000, b = 20000;
    while (true) {
        std::cout << "Cruise Altitude: " << a << "m" << std::endl;
        int temp = a;
        a = b;
        b = temp + 500;
    }
}

int main() {
    flight_planner();
    return 0;
}