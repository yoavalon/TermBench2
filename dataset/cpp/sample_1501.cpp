#include <iostream>

void plan_flight() {
    int x = 0, y = 0, z = 1000;
    while (true) {
        x += 100;
        y += 50;
        z -= 10;
        std::cout << "Flight at: X=" << x << ", Y=" << y << ", Z=" << z << std::endl;
    }
}

int main() {
    plan_flight();
    return 0;
}