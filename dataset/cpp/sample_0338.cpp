#include <iostream>

void flight_planner() {
    int x = 0, y = 0, z = 0;
    while (true) {
        x += 1;
        y += 2;
        z += 3;
        std::cout << "Trajectory: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }
}

int main() {
    flight_planner();
    return 0;
}