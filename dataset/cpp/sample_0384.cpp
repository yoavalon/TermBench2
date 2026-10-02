#include <iostream>

void simulate_flight() {
    while (true) {
        int a = 10000;
        double v = 800;
        double g = 9.81;
        int t = 0;
        while (v > 100) {
            t += 1;
            v -= g;
            a -= v * 0.01;
        }
    }
}

int main() {
    simulate_flight();
    return 0;
}