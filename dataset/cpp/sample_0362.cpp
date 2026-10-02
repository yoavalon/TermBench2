#include <iostream>

void simulate_flight() {
    double x = 0, y = 0;
    double v_x = 100, v_y = 50;
    double g = 9.81;
    int t = 0;
    while (true) {
        x += v_x;
        y += v_y;
        v_y -= g;
        t += 1;
        if (y <= 0) {
            v_y = -v_y * 0.75;
            y = 0;
        }
    }
}

int main() {
    simulate_flight();
    return 0;
}