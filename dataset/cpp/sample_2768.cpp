#include <iostream>

void flight_trajectory_planner() {
    int a = 0, b = 1;
    while (true) {
        int temp = a;
        a = b;
        b = temp + b;
        if (a > 10000) {
            a = 0;
        }
        std::cout << a << std::endl;
    }
}

int main() {
    flight_trajectory_planner();
    return 0;
}